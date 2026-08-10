// Chapter04_08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>

int main()
{
    using namespace std;
    //bool iteam1_flage = false;
    //bool iteam2_flage = false;
    //bool iteam3_flage = false;
    //bool iteam4_flage = false;
    const unsigned char opt0 = 1 << 0;
    const unsigned char opt1 = 1 << 1;
    const unsigned char opt2 = 1 << 2;
    const unsigned char opt3 = 1 << 3;

    cout << bitset<8>(opt0) << endl;
    cout << bitset<8>(opt1) << endl;
    cout << bitset<8>(opt2) << endl;
    cout << bitset<8>(opt3) << endl;

    unsigned char items_flage = 0;

    cout << "No item " << bitset<8>(items_flage) << endl;

    items_flage |= opt0;
    cout << "Item0 obtained " << bitset<8>(items_flage) << endl;

    items_flage |= opt3;
    cout << "Item3 obtained " << bitset<8>(items_flage) << endl;

    items_flage &= ~opt3;
    cout << "Item3 lost " << bitset<8>(items_flage) << endl;

    if (items_flage & opt1) { cout << "Has item1" << endl; }\
    else { cout << "Not hace item1" << endl; }

    if (items_flage & opt0) { cout << "Has item0" << endl; }

    items_flage |= (opt2 | opt3);
    cout << bitset<8>(opt2 | opt3) << endl;
    cout << "Item2, 3 obtained " << bitset<8>(items_flage) << endl;

    if ((items_flage & opt2) && !(items_flage & opt1)) // opt2 갖고 있고 opt1 갖고 있지 않을 때
    {
        //items_flage ^= opt2; // 1 1 이므로 0. 
        //items_flage ^= opt1; // 0 1 이므로 1.
        items_flage ^= (opt1 | opt2);
    }
    cout << bitset<8>(items_flage) << endl;

    const unsigned int red_mask = 0xFF0000;
    const unsigned int green_mask = 0x00FF00;
    const unsigned int blue_mask = 0x0000FF;
    
    cout << std::bitset<32>(red_mask) << endl;
    cout << std::bitset<32>(green_mask) << endl;
    cout << std::bitset<32>(blue_mask) << endl;


    unsigned int pixel_color = 0xDAA520;

    cout << std::bitset<32>(pixel_color) << endl;

    //unsigned char green = pixel_color & green_mask; // 2번째 칸이라서 못 받아옴
    unsigned char green = (pixel_color & green_mask) >> 8;
    unsigned char red = (pixel_color & red_mask) >> 16;
    unsigned char blue = pixel_color & blue_mask;

    cout << "red " << bitset<8>(red) << " " << int(red) << endl;
    cout << "green " << bitset<8>(green) << " " << int(green) << endl; 
    cout << "blue " << bitset<8>(blue) << " " << int(blue) << endl;

    return 0;
}

