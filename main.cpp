#include<iostream>
#include<fstream>
using namespace std;

struct techstack
{
    string name;
    string description;
    int score;
};
techstack tech[10] = {
    {"web frontend","building visual, interactive interfaces (React/JS)",0},
    {"web backend","server logic, APIs, and databases (Node/Express or similar)",0},
    {"mobile development","apps for phones",0},
    {"data science","extracting insight from data",0},
    {"machine learning/ AI","building predictive model and intelligent systems",0},
    {"game development","building interactive games and simulations",0},
    {"systems / embedded programming","low level,hardware-close code",0},
    {"clouds/ devops","deploying,scaling, and automating infrastructure",0},
    {"cybersecurity","finding and fixing vulnerabilities,securing systems",0},
    {"blockchain/web3","decentralized apps and smart contracts",0}
};
struct questions
{
    string question;
    string option_1, option_2, option_3, option_4;
    int target_1, target_2, target_3, target_4;
};
questions q[10]={
    {
        "Q1: What excites you most about building something?",
        "a) Making something people directly see and interact with",
        "b) Making a system that scales to millions of users behind the scenes",
        "c) Making a system that learns and improves from data",
        "d) Making something people can hold and play",
        0, 7, 4, 5   // 0=Web Frontend, 7=Cloud/DevOps, 4=ML/AI, 5=Game Dev
    },
    {
        "Q2: Which problem sounds most interesting to solve?",
        "a) How to store and retrieve data efficiently for an app",
        "b) How to catch a hacker before they cause damage",
        "c) How to make an app run smoothly on a small phone screen",
        "d) How to build a system nobody single party controls",
        1, 8, 2, 9   // 1=Web Backend, 8=Cybersecurity, 2=Mobile, 9=Blockchain
    },
    {
        "Q3: Numbers and data, or people and design?",
        "a) I love spreadsheets, trends, and patterns in numbers",
        "b) I love designing things that look and feel good",
        "c) I love writing code that talks directly to hardware",
        "d) I love training models that improve with more data",
        3, 0, 6, 4   // 3=Data Science, 0=Web Frontend, 6=Systems/Embedded, 4=ML/AI
    },
    {
        "Q4: How do you feel about working close to hardware?",
        "a) Love it - registers, memory, performance tuning excite me",
        "b) Neutral - I'd rather build on top of existing infrastructure",
        "c) Not for me - I prefer working in a browser or app",
        "d) I'd rather build for a game engine - hardware-adjacent but creative",
        6, 7, 0, 5   // 6=Systems/Embedded, 7=Cloud/DevOps, 0=Web Frontend, 5=Game Dev
    },
    {
        "Q5: Pick a project you'd want to build for fun",
        "a) A mobile app for tracking habits",
        "b) A model that predicts trends from data",
        "c) A 2D platformer game",
        "d) A tool that scans a website for security holes",
        2, 4, 5, 8   // 2=Mobile, 4=ML/AI, 5=Game Dev, 8=Cybersecurity
    },
    {
        "Q6: Solo tinkering or large-scale team systems?",
        "a) Small, contained projects I can finish solo",
        "b) Systems that need to handle huge scale and traffic",
        "c) Distributed systems where no single party is in control",
        "d) Backend logic connecting a database to an app",
        2, 7, 9, 1   // 2=Mobile, 7=Cloud/DevOps, 9=Blockchain, 1=Web Backend
    },
    {
        "Q7: What kind of invisible work appeals to you?",
        "a) Making sure servers never go down",
        "b) Making sure data is clean and trustworthy before analysis",
        "c) Making sure no attacker can break in",
        "d) Making sure code runs fast on limited hardware",
        7, 3, 8, 6   // 7=Cloud/DevOps, 3=Data Science, 8=Cybersecurity, 6=Systems/Embedded
    },
    {
        "Q8: If you had to give a demo, what would impress you most?",
        "a) A slick, animated web page",
        "b) A chatbot that gets smarter over time",
        "c) A game you built from scratch",
        "d) A smart contract executing with no middleman",
        0, 4, 5, 9   // 0=Web Frontend, 4=ML/AI, 5=Game Dev, 9=Blockchain
    },
    {
        "Q9: Pick your ideal daily task",
        "a) Writing API endpoints and managing a database",
        "b) Debugging a mobile app on a real device",
        "c) Automating deployment pipelines",
        "d) Auditing code for vulnerabilities",
        1, 2, 7, 8   // 1=Web Backend, 2=Mobile, 7=Cloud/DevOps, 8=Cybersecurity
    },
    {
        "Q10: What's your relationship with data?",
        "a) I want to visualize and find patterns in it",
        "b) I want to build models that predict from it",
        "c) I want to secure it from being stolen",
        "d) I want to store it in a decentralized, tamper-proof way",
        3, 4, 8, 9   // 3=Data Science, 4=ML/AI, 8=Cybersecurity, 9=Blockchain
    }
};
int main()
{
    ofstream logFile("results_log.csv", ios::app);
    cout << "enter your name : ";
    string name;
    cin.ignore();
    getline(cin, name);
    logFile << name << ",";
    for(int i = 0;i < 10;i++)
    {
        cout << q[i].question << endl;
        cout << q[i].option_1 << endl;
        cout << q[i].option_2 << endl;
        cout << q[i].option_3 << endl;
        cout << q[i].option_4 << endl;

        int choice;
        do
        {
            cout << "enter the choice (1/2/3/4): ";
            cin >> choice;
            if(choice < 1 || choice > 4)
            {
                cout << "invalid input! enter again" << endl;
            }
        } while (choice < 1 || choice > 4);
        
        

        int targetIndex;
        if (choice == 1) targetIndex = q[i].target_1;
        else if (choice == 2) targetIndex = q[i].target_2;
        else if (choice == 3) targetIndex = q[i].target_3;
        else if (choice == 4) targetIndex = q[i].target_4;

        tech[targetIndex].score++;
        system("pause");
        system("cls");
    }
    int firsthighest = -1, secondhighest = -1, thirdhighest = -1;
    for(int i = 0;i < 10;i++)
    {
        if (firsthighest == -1 || tech[i].score > tech[firsthighest].score)
        {
            thirdhighest = secondhighest;
            secondhighest = firsthighest;
            firsthighest = i;
        }
        else if (secondhighest == -1 || tech[i].score > tech[secondhighest].score)
        {
            thirdhighest = secondhighest;
            secondhighest = i;
        }
        else if (thirdhighest == -1 || tech[i].score > tech[thirdhighest].score)
        {
            thirdhighest = i;
        }
    }
    cout << "===============report===============" << endl;
    cout << "top recommendation : " << tech[firsthighest].name <<endl;
    cout << tech[firsthighest].description<< endl << endl;
    if (secondhighest != -1)
    {
    cout << "2nd recommendation : " << tech[secondhighest].name << endl;
    cout << tech[secondhighest].description << endl << endl;
    }
    if (thirdhighest != -1)
    {
    cout << "3rd recommendation : " << tech[thirdhighest].name << endl;
    cout << tech[thirdhighest].description << endl;
    }
    logFile << tech[firsthighest].name;
    if (secondhighest != -1) logFile << "," << tech[secondhighest].name;
    if (thirdhighest != -1) logFile << "," << tech[thirdhighest].name;
    logFile << endl;
    logFile.close();
    return 0;
};
