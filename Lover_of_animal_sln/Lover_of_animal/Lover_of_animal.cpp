 
#include <iostream>
#include <string>

#include <vector>

using namespace std;


class Person 
{
protected:
    string Name;
    string SecondName;
    string Patronymic;
    
public:

    string rol;

    virtual  void SetYourDatas() = 0
    {
        cout << "Ваша роль любитель собак\n";
        cout << "Введите ваше имя\n";
        cin >> Name;
        cout << "Введите ваше фамилию\n";
        cin >> SecondName;
        cout << "Введите ваше отчество\n";
        cin >> Patronymic;
    }

    double dengi=0;
    

    void Pozhertvovat() 
    {
        cout << "Хотите ли вы пожертвовать деньги?(y/n)";
        string da_net;

        cin >> da_net;
        if (da_net == "y")
        {
            cout << "Отлично введите сумму для пожертвования";
          
            cin >> dengi;
            cout << "Спасибо !";

        }
        else if (da_net == "n")
        {
            cout << "Понятно, очень жаль";
        }
        else
        {
            cout << "Вы ввели не правильное значение для выхода введите 'n'";
            do
            {
                cin >> da_net;
            } while (da_net != "n");
        }
    }

    virtual string MoyaStroka() = 0;
 
    
    
};


class Lover_Dog : public Person
{
public:
    
    Lover_Dog() 
    {
        SetYourDatas();
    }

    Lover_Dog(int i)
    {
        cout << "какая ваша любимая порода собак ?";
        cin >> poroda_sobaki;
    }

    string poroda_sobaki;
    void SetYourDatas()  override
    {
        Person::SetYourDatas(); 
        cout << "какая ваша любимая порода собак ?";
        cin >> poroda_sobaki;
        rol = "Собачник";

    }

    

    string MoyaStroka() override
    {
        string str = "Роль:" + rol + " любимая порода собаки: " + poroda_sobaki + " Имя: " + Name + " Фамилия: " + SecondName + " Отчество: " + Patronymic+" \n";
        str += "Внесенная сумма" + to_string(dengi) + "\n";
        return  str;
    }
};

class Lover_Cat : public Person
{
public:
    Lover_Cat() 
    {
        SetYourDatas();
    }
    Lover_Cat(int i)
    {
        cout << "какая ваша любимая порода кошки ?";
        cin >> poroda_cat;
    }


    string poroda_cat;
    void SetYourDatas() override
    {
        Person::SetYourDatas();
        cout << "какая ваша любимая порода кошки ?";
        cin >> poroda_cat;
        rol = "Кошатник";
    }

    string MoyaStroka() override
    {
        string str = "Роль:" + rol + " любимая порода кошки: " + poroda_cat + " Имя: " + Name + " Фамилия: " + SecondName + " Отчество: " + Patronymic + " \n";
        str += "Внесенная сумма" + to_string(dengi)+"\n";
        return  str;
    }


};

class Lubitel_Dog_Cat  :public Person
{
public:
    Lover_Cat* f_cat;
    Lover_Dog* f_dog;
    Lubitel_Dog_Cat() {
        cout << "Вы любитель и кошек и собак \n";
        SetYourDatas();
        rol = "dogs_and_cats";
        f_cat = new Lover_Cat(0);
        f_dog = new Lover_Dog(0);
    }

    string MoyaStroka() override 
    {
        string str = "Роль:" + rol + " любимая порода собаки: " + f_dog->poroda_sobaki + +" любимая порода кошки: " + f_cat->poroda_cat + " Имя: " + Name + " Фамилия: " + SecondName + " Отчество: " + Patronymic +" \n";
        str += "Внесенная сумма" + to_string(dengi) + "\n";
        return  str;
    }
    void SetYourDatas()  
    {
        Person::SetYourDatas();
    }
};








class Privetstvie 
{
public:
    Privetstvie() 
    {
        cout << "Здравствйте, это программа для любителей живтных";
        cout << "\n если вам больше по душе кошки введите 'cat' \n";
        cout << "если вам по душе больше собачки введите 'dog'\n";
        cout << "если вам нарвятся и те  и те введите 'cd'\n";
    }
};


#include <fstream>
int main()
{ 
    system("chcp 1251");

    vector<Person*> kolekts;


    cout << "Приветсвую!";
    string otvet;



    do {
       
        Privetstvie* privet= new Privetstvie();
        string vibor_p;
        cin >> vibor_p;
        if (vibor_p == "cat")
        {
            Lover_Cat* cat1 = new Lover_Cat();
            cat1->Pozhertvovat();
            kolekts.push_back(cat1);
        }
        else if (vibor_p == "dog")
        {
            Lover_Dog* dog_1 = new Lover_Dog();
            dog_1->Pozhertvovat();
            kolekts.push_back(dog_1);
        }
        else if (vibor_p == "cd")
        {
            Lubitel_Dog_Cat* dog_cat = new  Lubitel_Dog_Cat();
            dog_cat->Pozhertvovat();
            kolekts.push_back(dog_cat);
        }
        else
        {
            cout << "вы введи не то значение";
        }
        cout << "Хотите зарегестрировать еще одного человека?('da'/'net')";
        cin >> otvet;
    } while (otvet == "da");
 
    ofstream file;
    file.open("MyText.txt", ios::app);
    for (Person* p : kolekts) 
    {
        file << p->MoyaStroka();
    }
}

 