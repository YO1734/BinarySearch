
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int getRandomNumber(int min, long max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void FillArray(std::vector<int>& array, int size)
{
	for (int i = 0; i < size; i++)
	{

		array[i] = getRandomNumber(-10, 500);
	}
    std::cout << "";
}


void PrintArray(std::vector<int>& array, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << std::endl;
	}

}

int BinarySearch(const std::vector<int>* array, int target) {
    int left = 0;
    int right = array->size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if ((*array)[middle] == target) {
            return middle; // Искомое значение найдено, возвращаем индекс
        }

        if ((*array)[middle] < target) {
            left = middle + 1; // Искомое значение больше, продолжаем поиск в правой половине
        }
        else {
            right = middle - 1; // Искомое значение меньше, продолжаем поиск в левой половине
        }
    }

    return -11; // Искомое значение не найдено
}
//QuickSort
void QuickSort(std::vector<int>& array, int left, int right) //left- 0 index, right last index of size
{
	int i = left, j = right - 1;
	int temp;
	int pivot = array[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i <= j) {
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		QuickSort(array, left, j);
	if (i < right)
		QuickSort(array, i, right);

}


int KMPSearch(char* string, char* substring) {
	int sl, ssl;
	int res = -1;
	sl = strlen(string);
	ssl = strlen(substring);
	if (sl == 0)
		std::cout << "Невірно заданий рядок\n";
	else if (ssl == 0)
		std::cout << "Невірно заданий підрядок\n";
	else {
		int i, j = 0, k = -1;
		int* d;
		d = new int[1000];//масив довжини префіксів
		d[0] = -1;
		// заповнюємо масив довжини префіксів для зразка
		while (j < ssl - 1) {
			while (k >= 0 && substring[j] != substring[k])
				k = d[k];
			j++;
			k++;
			if (substring[j] == substring[k])
				d[j] = d[k];
			else
				d[j] = k;
		}
		i = 0; j = 0;
		// пошук входження підрядка
		while (j < ssl && i < sl) {
			while (j >= 0 && string[i] != substring[j])
				j = d[j];
			i++;
			j++;
		}
		delete[] d;
		//індекс першого входження підрядка
		res = j == ssl ? i - ssl : -1;
	}
	return res;
}


int main()
{
	// STL demonstraiting

	// Пример использования алгоритма find()
	std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int target = 6;
	auto it = std::find(numbers.begin(), numbers.end(), target);
	if (it != numbers.end()) {
		std::cout << "Element " << target << " found at index: " << std::distance(numbers.begin(), it) << std::endl;
	}
	else {
		std::cout << "Element " << target << " not found" << std::endl;
	}

	// Пример использования алгоритма find_if()
	std::vector<int> evenNumbers = { 2, 4, 6, 8, 10 };
	auto evenIt = std::find_if(evenNumbers.begin(), evenNumbers.end(), [](int num) { return num % 2 == 0; });
	if (evenIt != evenNumbers.end()) {
		std::cout << "First even number found: " << *evenIt << std::endl;
	}
	else {
		std::cout << "No even numbers found" << std::endl;
	}

	// Пример использования алгоритма find_first_of()
	std::string text = "Hello, world!";
	std::string vowels = "aeiou";
	auto vowelIt = std::find_first_of(text.begin(), text.end(), vowels.begin(), vowels.end());
	if (vowelIt != text.end()) {
		std::cout << "First vowel found: " << *vowelIt << std::endl;
	}
	else {
		std::cout << "No vowels found" << std::endl;
	}

	// Пример использования алгоритма find_end()
	std::string sentence = "I love programming and programming is fun!";
	std::string pattern = "programming";
	auto patternIt = std::find_end(sentence.begin(), sentence.end(), pattern.begin(), pattern.end());
	if (patternIt != sentence.end()) {
		std::cout << "Pattern found at index: " << std::distance(sentence.begin(), patternIt) << std::endl;
	}
	else {
		std::cout << "Pattern not found" << std::endl;
	}

	return 0;

/* KMP search
	char text[] = "Quantum physics, also known as quantum mechanics, is a fundamental theory in physics that describes the behavior of matter and energy at the smallest scales. It provides a mathematical framework to understand phenomena such as particle-wave duality, superposition, and entanglement.\n\nAt the core of quantum physics is the concept of a quantum, which refers to the smallest unit of energy. Quantum mechanics introduces the wavefunction, a mathematical function that describes the probability distribution of finding a particle in a particular state. Unlike classical physics, which deals with deterministic behavior, quantum mechanics introduces inherent uncertainty due to the wave-like nature of particles.";

	char substring[] = "at";

	int index=KMPSearch(text, substring);
	std::cout << "Index of searching  '" << substring << "' is " << index << std::endl;
*/

/* Binary Search
	srand(static_cast<unsigned int>(time(0)));
	rand();
    
    std::vector<int> array;
    array.resize(3000);
    FillArray(array, 3000);
	QuickSort(array, 0, 3000);
    int target = 56;
    int index = BinarySearch(&array, target);
    if (index != -11)
    {
        std::cout << "Value of " << target << " was found " << index << std::endl;
    }
    else
    {
        std::cout << "Value of " << target << " was not found " << std::endl;
    }
*/
}

