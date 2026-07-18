import { execFileSync } from "node:child_process";
import { mkdirSync, writeFileSync } from "node:fs";
import { dirname, resolve } from "node:path";

const args = process.argv.slice(2);
const outputIndex = args.indexOf("--output");
const outputPath = resolve(outputIndex >= 0 ? args[outputIndex + 1] : "assets/study-activity.svg");
const timeZone = "Asia/Seoul";

function dateKey(date) {
  const parts = new Intl.DateTimeFormat("en-US", {
    timeZone,
    year: "numeric",
    month: "2-digit",
    day: "2-digit",
  }).formatToParts(date);
  const values = Object.fromEntries(parts.map(({ type, value }) => [type, value]));
  return `${values.year}-${values.month}-${values.day}`;
}

function parseDateKey(value) {
  const [year, month, day] = value.split("-").map(Number);
  return new Date(Date.UTC(year, month - 1, day));
}

function addDays(date, days) {
  const result = new Date(date);
  result.setUTCDate(result.getUTCDate() + days);
  return result;
}

function differenceInDays(left, right) {
  return Math.round((left.getTime() - right.getTime()) / 86_400_000);
}

function escapeXml(value) {
  return String(value)
    .replaceAll("&", "&amp;")
    .replaceAll("<", "&lt;")
    .replaceAll(">", "&gt;")
    .replaceAll('"', "&quot;")
    .replaceAll("'", "&apos;");
}

function calculateLongestStreak(keys) {
  let longest = 0;
  let current = 0;
  let previous = null;
  for (const key of keys) {
    const date = parseDateKey(key);
    current = previous && differenceInDays(date, previous) === 1 ? current + 1 : 1;
    longest = Math.max(longest, current);
    previous = date;
  }
  return longest;
}

function calculateCurrentStreak(counts, today) {
  const yesterday = addDays(today, -1);
  let cursor = counts.has(dateKey(today)) ? today : counts.has(dateKey(yesterday)) ? yesterday : null;
  let streak = 0;
  while (cursor && counts.has(dateKey(cursor))) {
    streak += 1;
    cursor = addDays(cursor, -1);
  }
  return streak;
}

const log = execFileSync(
  "git",
  ["log", "HEAD", "--no-merges", "--format=%aI%x09%ae%x09%s"],
  { encoding: "utf8" },
).trim();

const counts = new Map();
let totalCommits = 0;
for (const line of log ? log.split(/\r?\n/) : []) {
  const [isoDate, email = "", subject = ""] = line.split("\t");
  if (!isoDate || /\[bot\]|github-actions/i.test(`${email} ${subject}`)) continue;
  const key = dateKey(new Date(isoDate));
  counts.set(key, (counts.get(key) ?? 0) + 1);
  totalCommits += 1;
}

const studyDays = [...counts.keys()].sort();
const todayKey = dateKey(new Date());
const today = parseDateKey(todayKey);
const start = addDays(today, -(today.getUTCDay() + 52 * 7));
const latestStudyDay = studyDays.at(-1) ?? "-";
const currentStreak = calculateCurrentStreak(counts, today);
const longestStreak = calculateLongestStreak(studyDays);

const width = 920;
const height = 222;
const cell = 12;
const gap = 3;
const pitch = cell + gap;
const gridX = 82;
const gridY = 92;
const monthNames = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"];

const monthLabels = [];
let previousMonth = -1;
for (let week = 0; week < 53; week += 1) {
  const weekDate = addDays(start, week * 7);
  const month = weekDate.getUTCMonth();
  if (month !== previousMonth && weekDate.getUTCDate() <= 7) {
    monthLabels.push(`<text class="month" x="${gridX + week * pitch}" y="76">${monthNames[month]}</text>`);
  }
  previousMonth = month;
}

const cells = [];
for (let offset = 0; offset <= differenceInDays(today, start); offset += 1) {
  const date = addDays(start, offset);
  const key = dateKey(date);
  const count = counts.get(key) ?? 0;
  const level = count === 0 ? 0 : count === 1 ? 1 : count === 2 ? 2 : count === 3 ? 3 : 4;
  const week = Math.floor(offset / 7);
  const day = date.getUTCDay();
  cells.push(
    `<rect class="level-${level}" x="${gridX + week * pitch}" y="${gridY + day * pitch}" width="${cell}" height="${cell}" rx="2">` +
      `<title>${escapeXml(key)}: ${count} commit${count === 1 ? "" : "s"}</title></rect>`,
  );
}

const summary = `${studyDays.length} study days, ${currentStreak} day current streak, ${longestStreak} day longest streak, ${totalCommits} commits.`;
const svg = `<?xml version="1.0" encoding="UTF-8"?>
<svg xmlns="http://www.w3.org/2000/svg" width="${width}" height="${height}" viewBox="0 0 ${width} ${height}" role="img" aria-labelledby="title desc">
  <title id="title">TBCppStudy repository study activity</title>
  <desc id="desc">${escapeXml(summary)}</desc>
  <style>
    .background { fill: #0d1117; stroke: #30363d; }
    text { font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", sans-serif; fill: #f0f6fc; }
    .heading { font-size: 18px; font-weight: 600; }
    .stat { font-size: 13px; fill: #8b949e; }
    .month, .weekday, .legend { font-size: 11px; fill: #8b949e; }
    .level-0 { fill: #161b22; }
    .level-1 { fill: #0e4429; }
    .level-2 { fill: #006d32; }
    .level-3 { fill: #26a641; }
    .level-4 { fill: #39d353; }
  </style>
  <rect class="background" x="0.5" y="0.5" width="${width - 1}" height="${height - 1}" rx="12" />
  <text class="heading" x="24" y="30">Study Activity · TBCppStudy</text>
  <text class="stat" x="24" y="54">Study days ${studyDays.length}  ·  Current streak ${currentStreak}d  ·  Longest streak ${longestStreak}d  ·  Commits ${totalCommits}  ·  Last study ${escapeXml(latestStudyDay)}</text>
  ${monthLabels.join("\n  ")}
  <text class="weekday" x="48" y="${gridY + pitch + 10}">Mon</text>
  <text class="weekday" x="48" y="${gridY + pitch * 3 + 10}">Wed</text>
  <text class="weekday" x="48" y="${gridY + pitch * 5 + 10}">Fri</text>
  ${cells.join("\n  ")}
  <text class="legend" x="${gridX + 46 * pitch}" y="211">Less</text>
  <rect class="level-0" x="${gridX + 49 * pitch}" y="200" width="${cell}" height="${cell}" rx="2" />
  <rect class="level-1" x="${gridX + 50 * pitch}" y="200" width="${cell}" height="${cell}" rx="2" />
  <rect class="level-2" x="${gridX + 51 * pitch}" y="200" width="${cell}" height="${cell}" rx="2" />
  <rect class="level-3" x="${gridX + 52 * pitch}" y="200" width="${cell}" height="${cell}" rx="2" />
  <text class="legend" x="${gridX + 53 * pitch + 4}" y="211">More</text>
</svg>
`;

mkdirSync(dirname(outputPath), { recursive: true });
writeFileSync(outputPath, svg, "utf8");
console.log(`Generated ${outputPath}`);
