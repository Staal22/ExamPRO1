#include "Main.h"

int main()
{
    menu();


    return 0;
}

void clearCin()
{
    std::cin.clear();
    std::cin.ignore(32767, '\n');
}

void menu()
{
    std::cout << "Which task do you want to access?" << std::endl
        << "(Enter a number from 1 to 3)" << std::endl
        << "Task 1 - String vectors" << std::endl
        << "Task 2 - The phone book" << std::endl
        << "Task 3 - The calculator" << std::endl;
    int task{};
    std::cin >> task;

    switch (task)
    {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    default:
        std::cout << "Invalid input\n";
        menu();
    }

}

void task1()
{
    count = SetOne.size();

    for (int i{}; i < count; i++)
    {
        for (int j{}; j < count; j++)
        {
            if (SetOne[i] == SetTwo[j])
                SetTwo[j] = "";
        }
    }

    for (int i{}; i < count; i++)
    {
        if (SetOne[i] == "")
            continue;
        std::cout << SetOne[i] << ", ";
    }
    for (int i{}; i < count; i++)
    {
        if (SetTwo[i] == "")
            continue;
        std::cout << SetTwo[i] << ", ";
    }

    std::cout << std::endl;
}

//most of the file related code is taken from my complusory 2 and 3 where i had already done most of what needed to be done
void task2()
{
    std::ifstream inf{ "userdb.txt" };

    if (!inf)
    {
        std::cerr << "Error: userdb.txt could not be opened for reading!\n";
        return;
    }

    std::cout << "The contents of the userdb.txt file are:\n";
    while (inf)
    {
        std::string strInput;
        std::getline(inf, strInput);
        std::cout << strInput << '\n';
    }

    inf.close();


    std::cout << "Would you like to..." << std::endl
        << "1. Add information to the file, or" << std::endl
        << "2. Search someone by their name?" << std::endl;
    int task{};
    std::cin >> task;

    switch (task)
    {
    case 1:
        newP = true;
        break;
    case 2:
        newP = false;
        break;
    default:
        std::cout << "Invalid input\n";
        task2();
    }

    again:
    clearCin();

    if (newP == true)
    {
        std::cout << "Please enter the name of the person you wish to add to the database : ";
        std::getline(std::cin, namestring);
        std::cout << std::endl;
        std::cout << "Please enter the phone number of the person you wish to add to the database : ";
        std::cin >> phonenumber;
        std::cout << std::endl;

        Person p1(namestring, phonenumber);

        std::cout << "Do you want to add another person to the database? (y/n)\n";
        std::cin >> response;
        if (response == 'y')
        {
            goto again;
        }
        else
            task2();
    }

    else if (newP == false)
    {
        std::cout << "Please enter the name to search : ";
        std::getline(std::cin, namestring);

        std::ifstream inf{ "userdb.txt" };
        while (inf)
        {
            std::string linecheck;
            std::getline(inf, linecheck);
            //std::cout << linecheck << " " << namestring;
            if (linecheck.find(namestring) != std::string::npos)
            {
                std::cout << "Match found!:\n" << linecheck;
            }
        }

        inf.close();
    }

}

// We do a little recursive descent parser
void task3()
{
    count = 1;

    int x = 4;
    int y = 0;

    for (int i{}; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            calc[i][j] = ' ';
        }
    }
    for (int i{}; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            cursor[i][j] = ' ';
        }
    }

    for (int i = 3; i > 0; i--) {
        for (int j{}; j < 3; j++) {
            calc[i][j] = count + '0';
            count++;
        }
    }

    calc[0][3] = '/';
    calc[1][3] = '*';
    calc[2][3] = '-';
    calc[3][3] = '+';
    calc[4][3] = 'E';
    calc[4][2] = '.';
    calc[4][1] = '0';
    calc[4][0] = 'C';

    do
    {
        cursor[x][y] = '>';

        if (answer == 0) {
            std::cout << "Use WASD to navigate" << std::endl
                << line << equation << line;
        }
        else if (answer != 0) {
            std::cout << "Pres 'C' to reset" << std::endl
                << line << answer << line;
        }

        for (int i = 0; i < 5; i++) {
            std::cout << '|';
            for (int j = 0; j < 4; j++) {
                std::cout << cursor[i][j] << calc[i][j] << '|';
            }
            std::cout << line;
        }

        char input = _getch();

        switch (input)
        {
        case 'w':
            if (x > 0) {
                cursor[x][y] = ' ';
                x = x - 1;
            }
            break;
        case 'a':
            if (y > 0) {
                cursor[x][y] = ' ';
                y = y - 1;
            }
            break;
        case 's':
            if (x < 4) {
                cursor[x][y] = ' ';
                x = x + 1;
            }
            break;
        case 'd':
            if (y < 3) {
                cursor[x][y] = ' ';
                y = y + 1;
            }
            break;
        case 13:
            switch (calc[x][y])
            {
            case 'E':
                equationC = equation.c_str();
                answer = expression();  //go parser go!
                break;
            case 'C':
                equation = "0";
                answer = 0;
                break;
            case '0':
                if (equation == "0")
                    ;
                else
                    equation.append("0");
                break;
            case '1':
                if (equation == "0")
                    equation = "1";
                else
                    equation.append("1");
                break;
            case '2':
                if (equation == "0")
                    equation = "2";
                else
                    equation.append("2");
                break;
            case '3':
                if (equation == "0")
                    equation = "3";
                else
                    equation.append("3");
                break;
            case '4':
                if (equation == "0")
                    equation = "4";
                else
                    equation.append("4");
                break;
            case '5':
                if (equation == "0")
                    equation = "5";
                else
                    equation.append("5");
                break;
            case '6':
                if (equation == "0")
                    equation = "6";
                else
                    equation.append("6");
                break;
            case '7':
                if (equation == "0")
                    equation = "7";
                else
                    equation.append("7");
                break;
            case '8':
                if (equation == "0")
                    equation = "8";
                else
                    equation.append("8");
                break;
            case '9':
                if (equation == "0")
                    equation = "9";
                else
                    equation.append("9");
                break;
            case '/':
                if (equation == "0")
                    break;
                else
                    equation.append("/");
                break;
            case '*':
                if (equation == "0")
                    break;
                else
                    equation.append("*");
                break;
            case '-':
                if (equation == "0")
                    break;
                else
                    equation.append("-");
                break;
            case '+':
                if (equation == "0")
                    break;
                else
                    equation.append("+");
                break;
            case '.':   //represented visually, but causes math to not work
                if (equation == "0")
                    break;
                else
                    equation.append(".");
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }

        system("cls");

    } while (true);
    
}

//checks the char we are currently pointing at
char peek()
{
    return *equationC;
}

//++ has higher precedence than * here, so first increment ecuationC (moving to next char in the string/array)
//and then return the value we pointed to before the increment
char get()
{
    return *equationC++;
}
//essentially get() gets called when we know we can move on the next char

int number()    //only called if we know we need to find a number
{
    int result = get() - '0';   //char '7' - '0' = int 7
    while (peek() >= '0' && peek() <= '9')  //as long as the current char is a number, we keep going
    {
        result = 10 * result + get() - '0'; //example: 32 read as 3*10+2, 457 as (((4)*10+5)*10+7) and so on
    }
    return result;
}

int factor()
{
    if (peek() >= '0' && peek() <= '9')
        return number();
    else if (peek() == '-')
    {
        get();  //move past the - sign
        return -factor();   //makes it so the value we will get from number() on the next iteration of factor() will be negative
    }
    return 0; // error
}

int term()
{
    int result = factor();  //can be negative or positive
    while (peek() == '*' || peek() == '/')
        if (get() == '*')
            result *= factor();
        else
            result /= factor(); //no error for dividing by 0 so watch out :)
    return result;
}

int expression()
{
    int result = term();
    while (peek() == '+' || peek() == '-')  //wait for + or - operator
        if (get() == '+')   //now use get() to move past the + sign
            result += term();
        else
            result -= term();
    return result;  //finished calculation
}