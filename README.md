# tech-stack-advisor-cpp
A C++ console tool that recommends a tech stack based on your interests
# Tech Stack Advisor

A C++ console application that recommends a technology stack based on your interests, working style, and what excites you about building software. Answer 10 multiple-choice questions and get personalized top-3 recommendations from a pool of 10 tech domains.

## What It Does

The advisor asks you a series of questions about your preferences — from what kind of problems you enjoy solving to whether you like working close to hardware or high in the application layer. Each answer contributes points toward relevant tech stacks. After all questions are answered, the program ranks and displays your top 3 best-fit recommendations, each with a short description.

Tech Stacks Covered:
Web Frontend · Web Backend · Mobile Development · Data Science/Analytics · Machine Learning/AI · Game Development · Systems/Embedded Programming · Cloud/DevOps · Cybersecurity · Blockchain/Web3

How It Works:
- Each tech stack is represented as a `struct` holding a name, description, and running score
- Each question is a `struct` holding the question text, 4 answer options, and 4 target indices — mapping each answer directly to the stack it should reward
- User answers are validated (numeric input, range-checked) via a `do-while` loop
- After all questions, a single pass through the stack array finds the top 3 highest-scoring stacks using manual insertion-style comparison logic (no `std::sort` — built entirely with raw arrays and structs)
- Stacks with a score of 0 are automatically excluded from the final report

Built With:
Pure C++ — no external libraries, no STL containers (`std::vector`, `<algorithm>`, etc.). Everything from data storage to sorting logic is implemented from scratch using structs, raw arrays, and control flow, as a deliberate exercise in understanding core mechanics before relying on standard library abstractions.

## How to Run
```bash
g++ main.cpp -o main
./main
```
Answer each question with a number from 1–4 when prompted.

## Sample Output
