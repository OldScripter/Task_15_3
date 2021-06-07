#include <iostream>
#include <vector>

std::vector<int> g_input_vector;

void PrintInputVector()
{
    std::cout << "| ";
    for (int i = 0; i < g_input_vector.size(); i++)
    {
        std::cout<< g_input_vector[i] << " | ";
    }
}

void ShowFifthFromSmallest()
{
    if (g_input_vector.size() < 5)
    {
        std::cout << "There are not enough elements inside of the vector to show you the fifth one.\n"
                     "Actual size of input vector is " << g_input_vector.size() << "\n";
        return;
    }

    for (int i = 0; i < g_input_vector.size(); i++)
    {
        for (int j = 0; j < g_input_vector.size() - i - 1; j++)
        {
            if (g_input_vector[j] > g_input_vector[j + 1])
            {
                int temp = g_input_vector[j];
                g_input_vector[j] = g_input_vector[j + 1];
                g_input_vector[j + 1] = temp;
            }
        }
    }
    std::cout << "Fifth element from smallest is " << g_input_vector[4] << "\n";
    std::cout << "Sorted array is:\n";
    PrintInputVector();
    std::cout << "\nPlease continue enter: \n";
    return;
}

int main() {

    std::cout << "Enter the number or:\n"
                 "-1 to show 5-th from down\n"
                 "-2 to exit the program\n";
    std::cout << "=============================\n";

    int input = 0;
    while (true)
    {
        std::cin >> input;
        std::cout << "Your input is " << input << ". Checking...\n";

        if (input == -1)
            ShowFifthFromSmallest();
        else if (input == -2)
            break;
        else
        {
            g_input_vector.push_back(input);
            std::cout << "Value is added to input vector.\n";
        }
    }

    std::cout << "Program is finished.\n";

    return 0;
}
