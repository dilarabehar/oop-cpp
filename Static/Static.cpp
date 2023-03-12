#include <iostream>

int generate()
{
    static int st{ 3 };  //derlemeyle birlikte oluştu ve program çalışmayı durdurana kadar aynı bellek adresinde locate etmeye devam edecek.
    int nonst{ 3 };   //fonksiyon oluşturulduğunda oluştu ve işlevini bitirdiğinde bellekten temiizlendi.
    std::cout<<"nonstatic val" << nonst<<"\t";

    ++st;
    return st;
}

int main()
{
    std::cout <<"static val" << generate() << "\n";
    std::cout << generate() << "\n";
    std::cout << generate() << "\n";
    std::cout << generate() << "\n";
    std::cout << generate() << "\n";

}


