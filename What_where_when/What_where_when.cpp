/*Задание 5. Реализация игры «Что? Где? Когда?»
Что нужно сделать
Реализуйте простую версию интеллектуальной игры «Что? Где? Когда?». 

Как происходит игра
В начале каждого хода игроки вращают волчок, то есть выбирают сектор на столе, который сейчас играет. Всего таких секторов 13. Сектор выбирается так: 
с клавиатуры вводится офсет (смещение) относительно текущего сектора на барабане. Исходя из этого офсета вычисляется новый активный сектор, который и
будет играть в этом ходе. Если выпавший сектор уже играл, выбирает следующий неигравший за ним. В начале всей игры стрелка установлена на первом секторе.

Как только играет какой-то из секторов, с него берётся письмо с вопросом — то есть считывается из файла данного сектора. Вопрос показывается на экране.

После того как вопрос показан, от игрока ожидается ответ на него. Игрок вводит этот ответ с помощью стандартного ввода. То, что он ввёл, сравнивается 
с ответом, который хранится во втором файле, ассоциированном с активным сектором. Данный файл должен содержать лишь одно слово-ответ.

Если ответ знатока-игрока был правильным, ему начисляется один балл. Если неверен, то балл уходит телезрителям.

Игра продолжается до тех пор, пока или игрок, или зрители не наберут шесть баллов. После этого называется победитель и программа заканчивает работу.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void chose_quest(int* sector, int* point) {
    while (*sector >= 12)
    {
        (*sector) -= 12;
    }
    *point += *sector;
}

int main()
{
    int guest_point = 0;
    int expert_point = 0;
    int sector = 0;
    int pointer = 0;
    char ch;



    string user_answer;
    string question_answer;
    string find_answer_in_quwstion;

    string questions [] = {"Question_1.txt","Question_2.txt", "Question_3.txt", "Question_4.txt", "Question_5.txt", "Question_6.txt", 
                            "Question_7.txt", "Question_8.txt", "Question_9.txt", "Question_10.txt", "Question_11.txt", "Question_12.txt", 
                            "Question_13.txt"};
    string sollo_quest;
    bool question_pool[] = { true, true, true, true, true, true, true, true, true, true, true, true, true };

    ifstream question;
    ifstream answer;

    while (true)
    {
        cout << "Input sector: ";
        cin >> sector;
        chose_quest(&sector, &pointer);

        while (!question_pool[sector])
        {
            sector++;
        }
        question_pool[sector] = false;
        question.open(questions[sector], ios::binary);

        question >> find_answer_in_quwstion;
        
        answer.open(find_answer_in_quwstion);

        while (question.get(ch))
        {
            cout << ch;

        }
        while (answer.get(ch))
        {
            question_answer += ch;
        }
        
        cout << "\n";
        getline(cin >> std::ws, user_answer);
        
        if (user_answer == question_answer)
        {
            cout << "Correct\n";
            expert_point++;
        }
        else
        {
            cout << "Incorect\n ";
            guest_point++;
        }
        question.close();
        answer.close();
        cout << "Your point: " << expert_point << " \n program point: " << guest_point<< "\n";
        user_answer.clear();
        question_answer.clear();
        if (expert_point == 6)
        {
            cout << "You WIN !";
            return 0;
        }
        else if(guest_point == 6)
        {
            cout << "You LOSE";
            return 0;
        }
    }   
}
