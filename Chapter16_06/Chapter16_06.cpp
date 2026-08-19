// Chapter16_06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Resource.h"

int main()
{
    
        /*Resource* res = new Resource(3);
        res->setAll(1);*/ // 이렇게 잘 안씀 make_shared로 사용
        
    {
        //std::shared_ptr<Resource> ptr1(res);

        auto ptr1 = std::make_shared<Resource>(3);
        ptr1->setAll(1);

        ptr1->print();
        {
            std::shared_ptr<Resource> ptr2(ptr1);
            //std::shared_ptr<Resource> ptr2(res); //(make_shared로 만들지 않았을 때)ptr1으로 만들지 않으면 ptr1 입장에서는 res의 소유권을 자기 말고 또 누가 갖고 있는지 알 수 없음 
            //auto ptr2 = ptr1;

            ptr2->setAll(3);
            ptr2->print();

            std::cout << "Going out of the block" << std::endl;
        }

        ptr1->print();

        std::cout << "Going out of the outer block" << std::endl;
    }

    return 0;
}


