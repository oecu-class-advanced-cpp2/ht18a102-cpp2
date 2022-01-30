#include <iostream>
#include <string>
#include<sstream>
namespace cpp2 {
    /* --------------------------------------------------------------------- */
    /*
    mcxi
    mcxi �L�@����͂���N���X�ł��B
    */
    /* --------------------------------------------------------------------- */
    class mcxi {
    private:
        int unit(char c) {
            switch (c) {
            case 'm':return 1000;
            case 'c':return 100;
            case 'x':return 10;
            case 'i':return 1;
            }
            //���W�ۑ�
            std::cout << "error:mcxi������ł�m,c,x,i��4�������g�p�ł��܂��B"<<c <<"�͖����ȕ����ł��B"<< std::endl;
            return -1;
        }
    public:
        int value_;
        mcxi(const std::string& s);      // �R���X�g���N�^
        std::string to_string();            // mcxi��int��
    };



    // �R���X�g���N�^
    mcxi::mcxi(const std::string& s) :value_(0){
        int num = 0;
        for (auto pos = s.begin(); pos != s.end(); ++pos) {
            // pos�������̂Ƃ�
            if (*pos >= '2' && *pos <= '9') {

                //���W�ۑ�
                if (num != 0) {
                    std::cout << "error:mcxi������ł͐����͘A�����đ����܂���" << std::endl;
                    return;
                }

                num = *pos - '0';
                // pos�������̂Ƃ�
            }

            //���W�ۑ�
            else if (*pos == '1'){
                std::cout << "error:mcxi������ł�1�͎g�p���܂���i�ȗ����܂��j" << std::endl;
                return;
            
            }else {
                int u = unit(*pos);
                if (num == 0)num = 1;
                value_ += num * u;
                num = 0;
            }
        }
       // std::cout << "(debug):value is :" << value_ << std::endl;
    }

    // int��mcxi��
    std::string mcxi::to_string(){
        {
            std::stringstream ss;
            int q = 0;

            // 1������(i)
            q = value_ % 10;
            if (q == 1) {
                ss << 'i';
            }
            if (q > 1) {
                ss << q;
                ss << 'm';
            }

            // 2������(x)
            q = (value_ / 10) % 10;
            if (q == 1) {
                ss << 'x';
            }
            if (q > 1) {
                ss << q;
                ss << 'x';
            }

            // 3������(c)
            q = (value_ / 100) % 10;
            if (q == 1) {
                ss << 'c';
            }
            if (q > 1) {
                ss << q;
                ss << 'c';
            }

            // 4������(m)
            q = value_ / 1000;
            if (q == 1) {
                ss << 'm';
            }
            if (q > 1) {
                ss << q;
                ss << 'i';
            }

            return ss.str();
        }
    }

    // �����Z�̒�`
    // int�^�̓�����Ԃ�
    mcxi operator+ (mcxi a, mcxi b)
    {
        //std::cout << "(debug):value mcxi.a :" << a.value_ << std::endl;
        //std::cout << "(debug):value mcxi.a :" << b.value_ << std::endl;
        mcxi result("");
        result.value_ = a.value_ + b.value_;
        return result;
    }

};

int main() {
    cpp2::mcxi a0("xi");
    cpp2::mcxi b0("x9i");
    cpp2::mcxi result0 = a0 + b0;
    std::cout << "3x" << " " << result0.to_string() << std::endl;
    cpp2::mcxi a1("i");
    cpp2::mcxi b1("9i");
    cpp2::mcxi result1 = a1 + b1;
    std::cout << "x" << " " << result1.to_string() << std::endl;
    cpp2::mcxi a2("c2x2i");
    cpp2::mcxi b2("4c8x8i");
    cpp2::mcxi result2 = a2 + b2;
    std::cout << "6cx" << " " << result2.to_string() << std::endl;
    cpp2::mcxi a3("m2ci");
    cpp2::mcxi b3("4m7c9x8i");
    cpp2::mcxi result3 = a3 + b3;
    std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;
    cpp2::mcxi a4("9c9x9i");
    cpp2::mcxi b4("i");
    cpp2::mcxi result4 = a4 + b4;
    std::cout << "m" << " " << result4.to_string() << std::endl;
    cpp2::mcxi a5("i");
    cpp2::mcxi b5("9m9c9x8i");
    cpp2::mcxi result5 = a5 + b5;
    std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;
    cpp2::mcxi a6("m");
    cpp2::mcxi b6("i");
    cpp2::mcxi result6 = a6 + b6;
    std::cout << "mi" << " " << result6.to_string() << std::endl;
    cpp2::mcxi a7("i");
    cpp2::mcxi b7("m");
    cpp2::mcxi result7 = a7 + b7;
    std::cout << "mi" << " " << result7.to_string() << std::endl;
    cpp2::mcxi a8("m9i");
    cpp2::mcxi b8("i");
    cpp2::mcxi result8 = a8 + b8;
    std::cout << "mx" << " " << result8.to_string() << std::endl;
    cpp2::mcxi a9("9m8c7xi");
    cpp2::mcxi b9("c2x8i");
    cpp2::mcxi result9 = a9 + b9;
    std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;
}