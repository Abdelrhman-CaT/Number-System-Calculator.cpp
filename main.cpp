#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <sstream>
using namespace std;

/*
    programmed by: Mr_CaT
    Date: 6th August 2019, Tuesday
    Size 1.66 MB

    Usage: This program is used to work with Binary, Decimal, Hexadecimal and Octal numbers with a total of 57 different method to apply on these numbers

    Update: added feature in decimal section: Smallest signed number represented by n bits

*/


int WORD_SIZE ;
string to_num[129] , to_num2[129] , outhex[129];
int in[129] , in2[129] , out[129];

bool is_hexa()
{
    if(to_num[0] == "0" && to_num[1]=="x")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool is_hexa2()
{
    if(to_num2[0] == "0" && to_num2[1]=="x")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool is_decimal(int len)
{
    if(to_num[len] == "d")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool is_binary(int len)
{
    if(to_num[len] == "b" || to_num[len] == "s")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool is_signed_binary(int len)
{
    if(to_num[len] == "s")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool is_signed_binary2()
{
    if(to_num2[35] == "s")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void hexa_map(int len)
{
    for(int i=2 ; i<len ; i++)
    {
        if(to_num[i] == "A")
        {
            to_num[i] = "10";
        }
        else if(to_num[i] == "B")
        {
            to_num[i] = "11";
        }
        else if(to_num[i] == "C")
        {
            to_num[i] = "12";
        }
        else if(to_num[i] == "D")
        {
            to_num[i] = "13";
        }
        else if(to_num[i] == "E")
        {
            to_num[i] = "14";
        }
        else if(to_num[i] == "F")
        {
            to_num[i] = "15";
        }

    }
}


void hexa_map2(int len)
{
    for(int i=2 ; i<len ; i++)
    {
        if(to_num2[i] == "A")
        {
            to_num2[i] = "10";
        }
        else if(to_num2[i] == "B")
        {
            to_num2[i] = "11";
        }
        else if(to_num2[i] == "C")
        {
            to_num2[i] = "12";
        }
        else if(to_num2[i] == "D")
        {
            to_num2[i] = "13";
        }
        else if(to_num2[i] == "E")
        {
            to_num2[i] = "14";
        }
        else if(to_num2[i] == "F")
        {
            to_num2[i] = "15";
        }

    }
}

void n(int len)
{
    if(is_hexa())
    {
        hexa_map(len);
        for(int i=2 ; i<len ; i++)
        {
            in[i-2] = atoi(to_num[i].c_str());
        }
    }
    else
    {
        for(int i=0 ; i<len ; i++)
        {
            in[i] = atoi(to_num[i].c_str());
        }
    }
}

void n2(int len)
{
    if(is_hexa2())
    {
        hexa_map2(len);
        for(int i=2 ; i<len ; i++)
        {
            in2[i-2] = atoi(to_num2[i].c_str());
        }
    }
    else
    {
        for(int i=0 ; i<len ; i++)
        {
            in2[i] = atoi(to_num2[i].c_str());
        }
    }
}

int signed_binary_decimal()
{
    int res=0;
    int i , j=0;
    for(i=WORD_SIZE-1,j=0 ; i>0 ; i-- , j++)
    {
        res+=(in[i] * pow(2,j));
    }
    res += -1 * in[0] * pow(2,j);
    return res;
}

int binary_decimal(int len)
{
    int res=0;
    if(is_signed_binary(len))
    {
        signed_binary_decimal();
    }
    else
    {
        for(int i=len-1,j=0 ; i>=0 ; i-- , j++)
        {
            res+=(in[i] * pow(2,j));
        }
        return res;
    }
}


int signed_binary_decimal2()
{
    int res=0;
    int i , j=0;
    for(i=WORD_SIZE-1,j=0 ; i>0 ; i-- , j++)
    {
        res+=(in2[i] * pow(2,j));
    }
    res += -1 * in2[0] * pow(2,j);
    return res;
}


int binary_decimal2(int len)
{
    int res=0;
    if(is_signed_binary2())
    {
        signed_binary_decimal2();
    }
    else
    {
        for(int i=len-1,j=0 ; i>=0 ; i-- , j++)
        {
            res+=(in2[i] * pow(2,j));
        }
        return res;
    }
}

void print_out()
{
    for(int i=WORD_SIZE-1 ; i>=0 ; i--)
    {
        cout << out[i] << " ";
    }
}

void print_out_exact()
{
    for(int i=0 ; i<WORD_SIZE ; i++)
    {
        cout << out[i] << " ";
    }
}

void not_gate()
{
    for(int i=0 ; i<WORD_SIZE ; i++)
    {
        if(in[i] == 0)
        {
            in[i] = 1;
        }
        else if(in[i] == 1)
        {
            in[i] = 0;
        }
    }
}

void plus1()
{
    if(in[WORD_SIZE-1] == 0)
    {
        in[WORD_SIZE-1] = 1;
    }
    else
    {
        in[WORD_SIZE-1] = 0;
        int i = WORD_SIZE-2;

        while(i>=0)
        {
            if(in[i] == 0)
            {
                in[i] = 1;
                break;
            }
            else
            {
                in[i] = 0;
                i--;
            }
        }

    }
}

void d_tcompliment()
{
    for(int i=WORD_SIZE-1 ,j=0 ; i>=0 ; i-- , j++)
    {
        in[j] = out[i];
    }
    not_gate();
    plus1();
}

void t_complimetn()
{
    not_gate();
    plus1();
}

void decimal_binary(int d)
{
    if(d==0)
    {
        for(int i=0 ; i<WORD_SIZE ; i++)
        {
            out[i] = 0;
        }
    }
    else if(d<0)
    {
        d = d * -1;
        decimal_binary(d);
        d_tcompliment();
    }
    else
    {
        int q=0;
        while(d!=0)
        {
            out[q] = d%2;
            d=d/2;
            q++;
        }
        if(q < WORD_SIZE)
        {
            for(int i=q ; i< WORD_SIZE ; i++)
            {
                out[i] = 0;
            }
        }
    }
}

int hexa_decimal(int len)
{
    int res=0;
    for(int i=len-3 , j=0 ; i>=0 ; i-- , j++)
    {
        res+=(in[i] * pow(16,j));
    }
    return res;
}

int hexa_decimal2(int len)
{
    int res=0;
    for(int i=len-3 , j=0 ; i>=0 ; i-- , j++)
    {
        res+=(in2[i] * pow(16,j));
    }
    return res;
}


void hexa_unmap(int r , int q)
{
    if(r<10)
    {
        ostringstream ss;
        ss << r;
        string rr;
        rr = ss.str();
        outhex[q] = rr;
    }
    else
    {
        if(r==10)
        {
            outhex[q] = "A";
        }
        else if(r==11)
        {
            outhex[q] = "B";
        }
        else if(r==12)
        {
            outhex[q] = "C";
        }
        else if(r==13)
        {
            outhex[q] = "D";
        }
        else if(r==14)
        {
            outhex[q] = "E";
        }
        else if(r==15)
        {
            outhex[q] = "F";
        }
    }
}

void print_outhex()
{
    cout << "0 " << "x ";
    for(int i=WORD_SIZE/4 - 1 ; i>=0 ; i--)
    {
        cout << outhex[i] << " ";
    }
}

void print_outhex_exact()
{
    cout << "0 x ";
    for(int i=0 ; i<WORD_SIZE ; i++)
    {
        cout << outhex[i] << " ";
    }
}


void decimal_hexa(int d)
{
    int q=0;
    if(d==0)
    {
        for(int i=0 ; i<WORD_SIZE/4 ; i++)
        {
            outhex[i] = "0";
        }
    }
    else
    {
        while(d!=0)
        {
            int r=d%16;
            hexa_unmap(r,q);
            q++;
            d=d/16;
        }
        if(q<WORD_SIZE/4)
        {
            for(int i=q ; i<WORD_SIZE/4 ; i++)
            {
                outhex[i] = "0";
            }
        }
    }
}

void binary_hexa(int len)
{
    decimal_hexa(binary_decimal(len));
}

void hexa_binary(int len)
{
    decimal_binary(hexa_decimal(len));
}

int ndigits(int d)
{
    int res=1;
    if(d==0)
    {
        return res;
    }
    res = ceil(log2(d)+0.0001);
    return res;
}

bool is_octal(int len)
{
    if(to_num[len] == "o")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int octal_decimal(int len)
{
    int res=0;
    for(int i=len-1,j=0 ; i>=0 ; i--,j++)
    {
        res+=in[i] * pow(8,j);
    }
    return res;
}


void octal_binary(int len)
{
    decimal_binary(octal_decimal(len));
}

void octal_hexa(int len)
{
    decimal_hexa(octal_decimal(len));
    print_outhex();
}



void print_in()
{
    for(int i=0 ; i<WORD_SIZE ; i++)
    {
        cout << in[i] << " ";
    }
}


int d_not_gate(int len)
{
    decimal_binary(in[0]);
    for(int i=WORD_SIZE-1 , j=0 ; i>=0 ; i--,j++)
    {
        in[j] = out[i];
    }
    not_gate();
    return binary_decimal(len);
}

void h_not_gate(int len)
{
    hexa_map(len);
    for(int i=0 ; i<len-2 ; i++)
    {
        in[i] = fabs(in[i]-15);
        ostringstream nn;
        nn << in[i];
        outhex[i] = nn.str();
        if(outhex[i]=="10")
        {
            outhex[i] = "A";
        }
        else if(outhex[i]=="11")
        {
            outhex[i] = "B";
        }
        else if(outhex[i]=="12")
        {
            outhex[i] = "C";
        }
        else if(outhex[i]=="13")
        {
            outhex[i] = "D";
        }
        else if(outhex[i]=="14")
        {
            outhex[i] = "E";
        }
        else if(outhex[i]=="15")
        {
            outhex[i] = "F";
        }
    }
}

void o_not_gate(int len)
{
    for(int i=0 ; i<len ; i++)
    {
        in[i] = fabs(in[i]-7);
    }
}

void and_gate(int len)
{
    for(int i=0 ; i<len ; i++)
    {
        if(in[i] != in2[i])
        {
            out[i] = 0;
        }
        else
        {
            if(in[i] == 1)
            {
                out[i] = 1;
            }
            else
            {
                out[i] = 0;
            }
        }
    }
}


int d_and_gate(int len , int s_d)
{
    decimal_binary(in[0]);
    for(int i=len-1,j=0 ; i>=0 ; i-- , j++)
    {
        in[j] = out[i];
    }
    decimal_binary(s_d);
    for(int i=len-1,j=0 ; i>=0 ; i-- , j++)
    {
        in2[j] = out[i];
    }
    and_gate(len);
    for(int i=0 ; i<len ; i++)
    {
        in[i] = out[i];
    }
    return binary_decimal(len);
}

void or_gate(int len)
{
    for(int i=0 ; i< len ; i++)
    {
        if(in[i] == 1 || in2[i] == 1)
        {
            out[i] = 1;
        }
        else
        {
            out[i] = 0;
        }
    }
}

void xor_gate(int len)
{
    for(int i=0 ; i<len ; i++)
    {
        if(in[i] == in2[i])
        {
            out[i] = 0;
        }
        else
        {
            out[i] = 1;
        }
    }
}

int d_xor_gate(int len , int s_d)
{
    decimal_binary(in[0]);
    for(int i=len-1,j=0 ; i>=0 ; i-- , j++)
    {
        in[j] = out[i];
    }
    decimal_binary(s_d);
    for(int i=len-1,j=0 ; i>=0 ; i-- , j++)
    {
        in2[j] = out[i];
    }
    xor_gate(len);
    for(int i=0 ; i<len ; i++)
    {
        in[i] = out[i];
    }
    return binary_decimal(len);
}

int d_or_gate(int len , int s_d)
{
    decimal_binary(in[0]);
    for(int i=len-1,j=0 ; i>=0 ; i-- , j++)
    {
        in[j] = out[i];
    }
    decimal_binary(s_d);
    for(int i=len-1,j=0 ; i>=0 ; i-- , j++)
    {
        in2[j] = out[i];
    }
    or_gate(len);
    for(int i=0 ; i<len ; i++)
    {
        in[i] = out[i];
    }
    return binary_decimal(len);
}
void h_xor_gate(int len)
{
    hexa_binary(len);
    for(int i=WORD_SIZE-1 , j=0 ; i>=0 ; i-- , j++)
    {
        in[j] = out[i];
    }
    decimal_binary(hexa_decimal2(len));
    for(int i=WORD_SIZE-1 , j=0 ; i>=0 ; i-- , j++)
    {
        in2[j] = out[i];
    }

    xor_gate(WORD_SIZE);

    for(int i=0 ; i<WORD_SIZE ; i++)
    {
        in[i] = out[i];
    }

    binary_hexa(WORD_SIZE);
}


void h_and_gate(int len)
{
    hexa_binary(len);
    for(int i=WORD_SIZE-1 , j=0 ; i>=0 ; i-- , j++)
    {
        in[j] = out[i];
    }
    decimal_binary(hexa_decimal2(len));
    for(int i=WORD_SIZE-1 , j=0 ; i>=0 ; i-- , j++)
    {
        in2[j] = out[i];
    }

    and_gate(WORD_SIZE);

    for(int i=0 ; i<WORD_SIZE ; i++)
    {
        in[i] = out[i];
    }

    binary_hexa(WORD_SIZE);
}


void h_or_gate(int len)
{
    hexa_binary(len);
    for(int i=WORD_SIZE-1 , j=0 ; i>=0 ; i-- , j++)
    {
        in[j] = out[i];
    }
    decimal_binary(hexa_decimal2(len));
    for(int i=WORD_SIZE-1 , j=0 ; i>=0 ; i-- , j++)
    {
        in2[j] = out[i];
    }

    or_gate(WORD_SIZE);

    for(int i=0 ; i<WORD_SIZE ; i++)
    {
        in[i] = out[i];
    }

    binary_hexa(WORD_SIZE);
}

void signed_decimal_hexa(int d)
{
    decimal_binary(d);
    binary_hexa(WORD_SIZE);
}

void signed_binary_hexa()
{
    signed_decimal_hexa(signed_binary_decimal());
}



int signed_hexa_decimal(int len)
{
    if(in[0]<8)
    {
        return hexa_decimal(len);
    }
    else
    {
       hexa_binary(len);
       for(int i=WORD_SIZE-1 , j=0 ; i>=0 ; i-- , j++)
       {
           in[j] = out[i];
       }
       return signed_binary_decimal();
    }
}

void signed_hexa_binary(int len)
{
    if(in[0] < 8)
    {
        hexa_binary(len);
    }
    else
    {
        decimal_binary(signed_hexa_decimal(len));
    }
}

int decimal_add()
{
    return in[0] + in2[0];
}

int decimal_sub()
{
    return in[0] - in2[0];
}

int decimal_mult()
{
    return in[0] * in2[0];
}

float decimal_div()
{
    float a=(float) in[0];
    return a/in2[0];
}

void decimal_binary_add()
{
    decimal_binary(decimal_add());
}

void decimal_binary_sub()
{
    decimal_binary(decimal_sub());
}

void decimal_binary_mult()
{
    decimal_binary(decimal_mult());
}

void decimal_binary_div()
{
    decimal_binary((int)decimal_div());
}

void decimal_hexa_add()
{
    int x = decimal_add();
    if(x>=0)
    {
        decimal_hexa(x);
    }
    else if(x<0)
    {
        signed_decimal_hexa(x);
    }
}

void decimal_hexa_sub()
{
    int x = decimal_sub();
    if(x>=0)
    {
        decimal_hexa(x);
    }
    else if(x<0)
    {
        signed_decimal_hexa(x);
    }
}

void decimal_hexa_mult()
{
    int x = decimal_mult();
    if(x>=0)
    {
        decimal_hexa(x);
    }
    else if(x<0)
    {
        signed_decimal_hexa(x);
    }
}

void decimal_hexa_div()
{
    int x = decimal_div();
    if(x>=0)
    {
        decimal_hexa(x);
    }
    else if(x<0)
    {
        signed_decimal_hexa(x);
    }
}

void binary_binary_add()
{
    decimal_binary(binary_decimal(WORD_SIZE)+binary_decimal2(WORD_SIZE));
}

void binary_binary_sub()
{
    decimal_binary(binary_decimal(WORD_SIZE)-binary_decimal2(WORD_SIZE));
}

void binary_binary_mult()
{
    decimal_binary(binary_decimal(WORD_SIZE)*binary_decimal2(WORD_SIZE));
}

void binary_binary_div()
{
    decimal_binary(binary_decimal(WORD_SIZE)/binary_decimal2(WORD_SIZE));
}

int binary_decimal_addition()
{
   return (binary_decimal(WORD_SIZE) + binary_decimal2(WORD_SIZE));
}

int binary_decimal_subtraction()
{
    return (binary_decimal(WORD_SIZE) - binary_decimal2(WORD_SIZE));
}

int binary_decimal_multiplication()
{
    return (binary_decimal(WORD_SIZE) * binary_decimal2(WORD_SIZE));
}

float binary_decimal_division()
{
    return ( (float)binary_decimal(WORD_SIZE) / binary_decimal2(WORD_SIZE));
}

void binary_plus_decimal_binary()
{
    decimal_binary(binary_decimal(WORD_SIZE)+in2[0]);
}

int binary_plus_decimal_decimal()
{
    return binary_decimal(WORD_SIZE)+in2[0];
}

void binary_hexa_addition()
{
    if(binary_decimal_addition() < 0)
    {
        signed_decimal_hexa(binary_decimal_addition());
    }
    else
    {
        decimal_hexa(binary_decimal_addition());
    }
}

void binary_hexa_subtraction()
{
    if(binary_decimal_subtraction() < 0)
    {
        signed_decimal_hexa(binary_decimal_subtraction());
    }
    else
    {
        decimal_hexa(binary_decimal_subtraction());
    }
}

void binary_hexa_mult()
{
    if(binary_decimal_multiplication() < 0)
    {
        signed_decimal_hexa(binary_decimal_multiplication());
    }
    else
    {
        decimal_hexa(binary_decimal_multiplication());
    }
}

void binary_hexa_div()
{
    if(binary_decimal_division() < 0)
    {
        signed_decimal_hexa(binary_decimal_division());
    }
    else
    {
        decimal_hexa(binary_decimal_division());
    }
}


void hexa_plus_decimal(int len)
{
    int x= in2[0] + hexa_decimal(len);
    decimal_hexa(x);
    print_outhex();
}

void hexa_plus_hexa(int len)
{
    int x = hexa_decimal(len);
    int y = hexa_decimal2(len);
    decimal_hexa(x+y);
    print_outhex();
}








int main()
{
    string t;
    while(1)
    {
        cout << "Instructions:\n---------------\nType the number representation separated within by spaces\nAdd a proper radix to each number representation\n     binary -> b\n     signed binary -> s\n     hex -> h\n     decimal -> d\n     octal -> o\nWhile typing a hexadecimal, start it with 0 x then type the number\nDon't forget to add the radix at the end\n--------------------------------------------\n";
        cout << "Examples:\nTo enter 1001 in binary, type: 1 0 0 1 b\nTo enter 1010 in signed binary, type: 1 0 1 0 s\nTo enter 0x1AB in hexadecimal, type: 0 x 1 A B h\nTo enter 3 in decimal, type: 3 d\nTo enter 2 in octal, type: 2 o\n---------------\n";
        cout << "Enter a Number Representation:\n";
        int j=0,c=0;
    do
    {
        cin >> to_num[j];
        if(to_num[j] == "d" || to_num[j] == "b" || to_num[j] == "h" || to_num[j] == "o" || to_num[j] == "s")
        {
            break;
        }
        j++;
    }while(j<129);
    int len = j;
    n(len);

    cout << endl;


    if(is_hexa())
    {
        WORD_SIZE = (len-2)*4;

        cout << "Available methods:\n1- (Unsigned) Hexa to decimal\n2- (Signed) Hexa to decimal\n3- (Unsigned) Hexa to binary\n4- (signed) Hexa to binary\n5- NOT gate\n6- AND gate\n7- OR gate\n8- XOR gate\n9- Hexa+Decimal to hexa\n10- Hexa+Hexa to hexa\n\nTo restart type 0\n----------\nChoose one method by its number --> ";
        s: cin >> c;
        if(c == 1)
        {
            cout << "You chose (Unsigned) Hexa to decimal";
            cout << "\n" << hexa_decimal(len);
        }
        else if(c == 2)
        {
            cout << "You chose (Signed) Hexa to decimal";
            cout << "\n" << signed_hexa_decimal(len);
        }
        else if(c == 3)
        {
            cout << "You chose (Unsigned) Hexa to binary";
            hexa_binary(len);
            cout << endl;
            print_out();
        }
        else if (c == 4)
        {
            cout << "You chose (signed) Hexa to binary";
            cout << endl;
            signed_hexa_binary(len);
            print_in();
        }
        else if(c == 5)
        {
            cout << "You chose (Unsigned) NOT gate";
            h_not_gate(len);
            cout << endl;
            print_outhex_exact();
        }
        else if(c == 6 || c == 7 || c == 8)
        {
            cout << "Enter the second hexadecimal number:\n";

            for(int i=0 ; i<len ; i++)
            {
                cin >> to_num2[i];
            }
            cin >> to_num2[35];
            cout << endl;
            n2(len);
            if(c == 6)
            {
                cout << "You chose AND gate\n";
                h_and_gate(len);
            }
            else if(c == 7)
            {
                cout << "You chose OR gate\n";
                h_or_gate(len);
            }
            else if(c == 8)
            {
                cout << "You chose XOR gate\n";
                h_xor_gate(len);
            }
            print_outhex();
        }
        else if(c== 9)
        {
            cout << "Enter the decimal number:\n";
            cin >> in2[0];
            cin >> to_num2[35];
            cout << "You chose Hexa+Decimal to hexa\n";
            hexa_plus_decimal(len);
        }
        else if(c==10)
        {
            cout << "Enter the second hexadecimal number:\n";
            for(int i=0 ; i<len ; i++)
            {
                cin >> to_num2[i];
            }
            cin >> to_num2[35];
            n2(len);
            cout << "You chose Hexa+Hexa to hexa\n";
            hexa_plus_hexa(len);
        }
        else if(c == 0)
        {
            system("cls");
            continue;
        }
        else
        {
            cout << "\nERROR\n";
            cout << "try again: ";
            goto s;
        }
    }
    else if(is_binary(len))
    {
        WORD_SIZE = len;
        cout << "Available methods:\n1- Binary to decimal\n2- 2's Compliment\n3- Binary to hexa\n4- (Signed) Binary to hexa\n5- NOT gate\n6- AND gate\n7- OR gate\n8- XOR gate\n9- Binary-Binary addition\n10- Binary-Binary subtraction\n11- Binary-Binary multiplication\n12- Binary-Binary division\n13- Binary-Decimal addition\n14- Binary-Decimal subtraction\n15- Binary-Decimal multiplication\n16- Binary-Decimal division\n17- Binary-Hexa addition\n18- Binary-Hexa subtraction\n19- Binary-Hexa multiplication\n20- Binary-Hexa division\n21- Binary+Decimal to binary\n22- Binary+Decimal to decimal\n\nTo restart type 0\n----------\nChoose one method by its number --> ";
        t: cin >> c;
        if(c == 1)
        {
           cout << "You chose Binary to decimal";
           cout << "\n" << binary_decimal(len);
        }
        else if(c == 2)
        {
            int signedd=0;
            cout << "You chose 2's Compliment\n";
            if(binary_decimal(len)>0)
            {
                signedd=1;
            }
            t_complimetn();
            print_in();
            if(signedd == 1)
            {
                cout << "   (Signed) ";
            }
            if(signedd==1 && binary_decimal(len) > 0)
            {
                cout << "Overflow of 1 bit\n";
            }
            else
            {
                cout << endl;
            }
        }
        else if(c == 3)
        {
            cout << "You chose Binary to hexa";
            if(is_signed_binary(len))
            {
                signed_binary_hexa();
                cout << endl;
                print_outhex();
            }
            else
            {
                binary_hexa(len);
                cout << endl;
                print_outhex();
            }
        }
        else if(c == 4)
        {
            cout << "You chose (Signed) Binary to hexa";
            cout << endl;
            signed_binary_hexa();
            print_outhex();
        }
        else if(c == 5)
        {
            cout << "You chose NOT gate";
            cout << endl;
            not_gate();
            print_in();
        }
        else if(c == 6 || c == 7 || c == 8)
        {
            cout << "Enter the second binary number:\n";
            for(int i=0 ; i<len ; i++)
            {
                cin >> in2[i];
            }
            cin >> to_num[35];
            cout << endl;
            if(c == 6)
            {
                cout << "You chose AND gate\n";
                and_gate(len);
            }
            else if(c == 7)
            {
                cout << "You chose OR gate\n";
                or_gate(len);
            }
            else if(c == 8)
            {
                cout << "You chose XOR gate\n";
                xor_gate(len);
            }
            print_out_exact();
        }
        else if(c==9 || c==10 || c==11 || c==12)
        {
            cout << "Enter the second binary number:\n";
            for(int i=0 ; i<len ; i++)
            {
                cin >> in2[i];
            }
            cin >> to_num[35];
            cout << endl;

            if(c==9)
            {
                cout << "You chose Binary-Binary addition\n";
                if(binary_decimal(WORD_SIZE)+binary_decimal2(WORD_SIZE) < 0)
                {
                    binary_binary_add();
                    print_in();
                    cout << "   (Signed)";
                }
                else
                {
                    binary_binary_add();
                    print_out();
                }
            }
            else if(c==10)
            {
                cout << "You chose Binary-Binary subtraction\n";
                if(binary_decimal(WORD_SIZE)-binary_decimal2(WORD_SIZE) < 0)
                {
                    binary_binary_sub();
                    print_in();
                    cout << "   (Signed)";
                }
                else
                {
                    binary_binary_sub();
                    print_out();
                }
            }
            else if(c==11)
            {
                cout << "You chose Binary-Binary multiplication\n";
                if(binary_decimal(WORD_SIZE)*binary_decimal2(WORD_SIZE) < 0)
                {
                    binary_binary_mult();
                    print_in();
                    cout << "   (Signed)";
                }
                else
                {
                    binary_binary_mult();
                    print_out();
                }
            }
            else if(c==12)
            {
                cout << "You chose Binary-Binary division\n";
                if(binary_decimal(WORD_SIZE)/binary_decimal2(WORD_SIZE) < 0)
                {
                    binary_binary_div();
                    print_in();
                    cout << "   (Signed)";
                }
                else
                {
                    binary_binary_div();
                    print_out();
                }
            }
        }
        else if(c==13 || c==14 || c==15 || c==16)
        {
            cout << "Enter the second binary number:\n";
            for(int i=0 ; i<len ; i++)
            {
                cin >> in2[i];
            }
            cin >> to_num2[35];
            cout << endl;

            if(c==13)
            {
                cout << "You chose Binary-Decimal addition\n";
                cout << binary_decimal_addition();
            }
            else if(c==14)
            {
                cout << "You chose Binary-Decimal subtraction\n";
                cout << binary_decimal_subtraction();
            }
            else if(c==15)
            {
                cout << "You chose Binary-Decimal multiplication\n";
                cout << binary_decimal_multiplication();
            }
            else if(c==16)
            {
                cout << "You chose Binary-Decimal division\n";
                cout << binary_decimal_division();
            }
        }
        else if(c==17 || c==18 || c==19 || c==20)
        {
            cout << "Enter the second binary number:\n";
            for(int i=0 ; i<len ; i++)
            {
                cin >> in2[i];
            }
            cin >> to_num2[35];
            cout << endl;

            if(c==17)
            {
                cout << "You chose Binary-Hexa addition\n";
                binary_hexa_addition();
            }
            else if(c==18)
            {
                cout << "You chose Binary-Hexa subtraction\n";
                binary_hexa_subtraction();
            }
            else if(c==19)
            {
                cout << "You chose Binary-Hexa multiplication\n";
                binary_hexa_mult();
            }
            else if(c==20)
            {
                cout << "You chose Binary-Hexa division\n";
                binary_hexa_div();
            }
            print_outhex();
        }
        else if(c== 21 || c==22)
        {
            cout << "Enter the decimal number:\n";
            cin >> in2[0];
            cin >> to_num2[35];

            if(c==21)
            {
                cout << "You chose Binary+Decimal to binary\n";
                binary_plus_decimal_binary();
                print_out();
            }
            else if(c==22)
            {
                cout << "You chose Binary+Decimal to decimal\n";
                cout << binary_plus_decimal_decimal();
            }
        }
        else if(c == 0)
        {
            system("cls");
            continue;
        }
        else
        {
            cout << "\nERROR\n";
            cout << "try again: ";
            goto t;
        }
    }
    else if(is_decimal(len))
    {
        cout << "Available methods:\n1- Decimal to binary\n2- Decimal to hexa\n3- NOT gate\n4- AND gate\n5- OR gate\n6- XOR gate\n7- The maximum unsigned decimal number represented by "<< in[0] << " bits \n8- The maximum signed decimal number represented by " << in[0] << " bits\n9- Number of digits for binary representation\n10- Decimal-Decimal addition\n11- Decimal-Decimal subtraction\n12- Decimal-Decimal multiplication\n13- Decimal-Decimal division\n14- Decimal-Binary addition\n15- Decimal-Binary subtraction\n16- Decimal-Binary multiplication\n17- Decimal-Binary division\n18- Decimal-Hexa addition\n19- Decimal-Hexa subtraction\n20- Decimal-Hexa multiplication\n21- Decimal-Hexa division\n22- Smallest signed number represented by "<< in[0] <<" bits\n\nTo restart type 0\n----------\nchoose one method by its number --> ";
        u: cin >> c;

        if(c == 1)
        {
            cout << "You chose Decimal to binary\n";
             cout << "Enter the WORD size: ";
            cin >> WORD_SIZE;
            cout << endl;
            int p=1;
            if(in[0] < 0)
            {
                p=0;
            }
            decimal_binary(in[0]);
            if(p == 0)
            {
                print_in();
            }
            else
            {
                print_out();
            }
        }
        else if(c == 2)
        {
            cout << "You chose Decimal to hexa\n";
            cout << "Enter the WORD size: ";
            cin >> WORD_SIZE;
            cout << endl;
            if(in[0] < 0)
            {
                signed_decimal_hexa(in[0]);
            }
            else
            {
                decimal_hexa(in[0]);
            }
            print_outhex();
        }
        else if(c == 3)
        {
            cout << "You chose NOT gate\n";
            cout << "Enter the WORD size: ";
            cin >> WORD_SIZE;
            cout << "\n" << d_not_gate(WORD_SIZE);
        }
        else if(c == 4 || c == 5 || c == 6)
        {
            cout << "Enter the second decimal number:\n";
            int s_d;
            cin >> s_d;
            cin >> to_num[35];
            cout << endl;
            cout << "Enter the WORD size: ";
            cin >> WORD_SIZE;
            cout << endl;
            if(c == 4)
            {
                cout << "You chose AND gate\n";
                cout << d_and_gate(WORD_SIZE , s_d);
            }
            else if(c == 5)
            {
                cout << "You chose OR gate\n";
                cout << d_or_gate(WORD_SIZE , s_d);
            }
            else if(c == 6)
            {
                cout << "You chose XOR gate\n";
                cout << d_xor_gate(WORD_SIZE , s_d);
            }
        }
        else if(c == 7)
        {
            cout << "You chose The maximum unsigned decimal number represented by "<< in[0] << " bits";
            cout << endl;
            cout << pow(2 , in[0])-1;
        }
        else if(c == 8)
        {
            cout << "You chose The maximum signed decimal number represented by "<< in[0] << " bits";
            cout << endl;
            cout << pow(2 , (in[0]-1)) - 1;
        }
        else if(c == 9)
        {
            cout << "You chose Number of digits for binary representation";
            cout << endl;
            cout << ndigits(in[0]);
        }
        else if(c==10 || c==11 || c==12 || c==13)
        {
            cout << "Enter the second decimal number:\n";
            cin >> in2[0];
            cin >> to_num2[35];
            cout << endl;

            if(c==10)
            {
                cout << "You chose Decimal-Decimal addition";
                cout << "\n" << decimal_add();
            }
            else if(c==11)
            {
                cout << "You chose Decimal-Decimal subtraction";
                cout << "\n" << decimal_sub();
            }
            else if(c==12)
            {
                cout << "You chose Decimal-Decimal multiplication";
                cout << "\n" << decimal_mult();
            }
            else if(c==13)
            {
                cout << "You chose Decimal-Decimal division";
                cout << "\n" << decimal_div();
            }
        }
        else if(c==14 || c==15 || c==16 || c==17)
        {
            cout << "Enter the second decimal number:\n";
            cin >> in2[0];
            cin >> to_num2[35];
            cout << endl;
            cout << "Enter the WORD size: ";
            cin >> WORD_SIZE;

            if(c==14)
            {
                cout << "You chose Decimal-Binary addition\n";
                if(decimal_add()<0)
                {
                    decimal_binary_add();
                    print_in();
                    cout << "   (Signed)";
                }
                else
                {
                    decimal_binary_add();
                    print_out();
                }
            }
            else if(c==15)
            {
                cout << "You chose Decimal-Binary subtraction\n";
                if(decimal_sub()<0)
                {
                    decimal_binary_sub();
                    print_in();
                    cout << "   (Signed)";
                }
                else
                {
                    decimal_binary_sub();
                    print_out();
                }
            }
            else if(c==16)
            {
                cout << "You chose Decimal-Binary multiplication\n";
                if(decimal_mult()<0)
                {
                    decimal_binary_mult();
                    print_in();
                    cout << "   (Signed)";
                }
                else
                {
                    decimal_binary_mult();
                    print_out();
                }
            }
            else if(c==17)
            {
                cout << "You chose Decimal-Binary division\n";
                if(decimal_div()<0)
                {
                    decimal_binary_div();
                    print_in();
                    cout << "   (Signed)";
                }
                else
                {
                    decimal_binary_div();
                    print_out();
                }
            }
        }
        else if(c==18 || c==19 || c==20 || c==21)
        {
            cout << "Enter the second decimal number:\n";
            cin >> in2[0];
            cin >> to_num2[35];
            cout << endl;
            cout << "Enter the WORD size: ";
            cin >> WORD_SIZE;

            if(c==18)
            {
                cout << "You chose Decimal-Hexa addition\n";
                decimal_hexa_add();
                print_outhex();
            }
            else if(c==19)
            {
                cout << "You chose Decimal-Hexa subtraction\n";
                decimal_hexa_sub();
                print_outhex();
            }
            else if(c==20)
            {
                cout << "You chose Decimal-Hexa multiplication\n";
                decimal_hexa_mult();
                print_outhex();
            }
            else if(c==21)
            {
                cout << "You chose Decimal-Hexa division\n";
                decimal_hexa_div();
                print_outhex();
            }
        }
        else if(c==22)
            {
                cout << "You chose Smallest signed number represented by "<< in[0] <<" bits\n";
                cout << -1 * pow(2 , (in[0]-1)) << endl;
            }
        else if(c == 0)
        {
            system("cls");
            continue;
        }
        else
        {
            cout << "\nERROR\n";
            cout << "try again: ";
            goto u;
        }
    }

    else if(is_octal(len))
    {
       WORD_SIZE = len * 3;
       cout << "Available methods:\n1- Octal to decimal\n2- Octal to binary\n3- Octal to hexa\n4- NOT gate\n\nTo restart type 0\n----------\nchoose one method by its number --> ";
       v:cin >> c;
       if(c == 1)
       {
           cout << "You chose Octal to decimal";
           cout << endl;
           cout << octal_decimal(len);
       }
       else if(c == 2)
       {
           cout << "You chose Octal to binary";
           cout << endl;
           octal_binary(len);
           print_out();
       }
       else if(c == 3)
       {
           cout << "You chose Octal to hexa";
           cout << endl;
           octal_hexa(len);
       }
       else if(c == 4)
       {
           cout << "You chose NOT gate";
           cout << endl;
           o_not_gate(len);
           for(int i=0 ; i<len ; i++)
           {
               cout << in[i] << " ";
           }
       }
       else if(c == 0)
        {
            system("cls");
            continue;
        }
       else
       {
            cout << "\nERROR\n";
            cout << "try again: ";
            goto v;
       }
    }

    cout << "\n\nPowered by: Mr_CaT\ntype k to continue\n";
    cin >> t;
    if(t=="k")
    {
        system("cls");
    }
}
return 0;
}
