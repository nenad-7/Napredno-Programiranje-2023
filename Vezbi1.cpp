//Ovaj algoritam gi sortira dvete nizi spored Merge Sort algoritmot, koj prvo ja deli nizata na pola. Potoa dvete polovini se sortiraat vo edna celosna niza.
//Prvo ja pecati originalnata niza zadadena od primerot, pa ja sortira i ja pecati istata niza sortirana. Istoto e napraveno i spored moeto ime, prezime
// i indeks koi se pretvoreni vo ASCII kod kako integer.


#include <iostream>
using namespace std;
//defining the merge function to merge the two sorted halves of the given input array
void merge(int array[], int left, int middle, int right)
{
	//dividing the given array into two halves
	int fh = middle - left + 1;
	int sh = right - middle;
	//creating two temporary arrays
	int t1[fh], t2[sh];
	//copying the data from the two halves into two temporary arrays
	for (int m = 0; m < fh; m++)
		t1[m] = array[left + m];
	for (int n = 0; n < sh; n++)
		t2[n] = array[middle + 1 + n];
	//merging the temporary arrays into a single array
	int a = 0;
	int b = 0;
	int c = left;
	while (a < fh && b < sh) {
		if (t1[a] <= t2[b]) {
			array[c] = t1[a];
			a++;
		}
		else {
			array[c] = t2[b];
			b++;
		}
		c++;
	}
	while (a < fh) {
		array[c] = t1[a];
		a++;
		c++;
	}
	while (b < sh) {
		array[c] = t2[b];
		b++;
		c++;
	}
}
//sorting each of the divided arrays using mergeSort() function
void mergeSort(int array[], int left, int right) {
	if (left >= right) {
		return;
	}
	int middle = left + (right - left) / 2;
	mergeSort(array, left, middle);
	mergeSort(array, middle + 1, right);
	merge(array, left, middle, right);
}
// function to print the resulting array
void printArray(int Array[], int size)
{
	for (int d = 0; d < size; d++)
		cout << Array[d] << " ";
}
// defining the main function
int main()
{
	int array[] = { 20, 50, 10, 5, 25, 45 };

	int nizaIndeks[] = { (int)'N', (int)'e', (int)'n', (int)'a', (int)'d', (int)'D', (int)'i', (int)'m', (int)'c', (int)'h', (int)'e', (int)'v', (int)'s',(int)'k', (int)'i',
	(int)'I', (int)'N', (int)'K', (int)'I', 9, 5, 0 };

	int goleminaNiza = sizeof(nizaIndeks) / sizeof(nizaIndeks[0]);

	int array_size = sizeof(array) / sizeof(array[0]);

	cout << "The elements of the input array before sorting are: \n";
	printArray(array, array_size);
	mergeSort(array, 0, array_size - 1);
	cout << "\nThe elements of the input array after sorting are: \n";
	printArray(array, array_size);

	cout << "\n\n Elementite na vleznata niza pred sortiranje se: \n";
	printArray(nizaIndeks, goleminaNiza);
	mergeSort(nizaIndeks, 0, goleminaNiza - 1);

	cout << "\n Elementite na vleznata niza po sortiranje se: \n";
	printArray(nizaIndeks, goleminaNiza);

	return 0;
}