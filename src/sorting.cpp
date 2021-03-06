#include "sorting.hpp"

using namespace std;

void insertion_sort (vector<generic_register>& unsorted_values)
{
	int start = 0, end = unsorted_values.size() - 1;
	int current = start + 1;
	int aux;
	generic_register swap;

	while (current <= end) // Percorre todo o array
	{
		aux = current;
		while (aux > start)
		{
			if (unsorted_values[aux].key.compare(unsorted_values[aux-1].key) < 0) // Compara com os valores anteriores, troca se o anterior for maior
			{
				swap = unsorted_values[aux];
				unsorted_values[aux] = unsorted_values[aux-1];
				unsorted_values[aux-1] = swap;

				aux = aux - 1;
			}

			else 
				aux = start;
		}
		current ++;
	}
} // insertion_sort

// Admite que "sorted_values" ja esta ordenado a nao ser pelos ultimos elementos inseridos
void insertion_sort_inclusion ( vector <generic_register> &sorted_values, int number_insertions)
{
	int start = 0, end = sorted_values.size() - 1;
	int current = end - (number_insertions - 1); // Primeiro novo elemento a ser inserido
	int aux;
	generic_register swap;

	while (current <= end) // Percorre todo o array
	{
		aux = current;
		while (aux > start)
		{
			if (sorted_values[aux].key.compare(sorted_values[aux-1].key) < 0) // Compara com os valores anteriores, troca se o anterior for maior
			{
				swap = sorted_values[aux];
				sorted_values[aux] = sorted_values[aux-1];
				sorted_values[aux-1] = swap;

				aux = aux - 1;
			}

			else 
				aux = start;
		}
		current ++;
	}
} // insertion_sort_inclusion

void heapsort (vector <generic_register> &unsorted_values)
{
	int size = unsorted_values.size();
	generic_register swap;

	create_max_heap (unsorted_values);

	// Ordena o vetor

	while ( size > 1 )
	{
		// Troca o maior valor do heap com aquele no final dele e diminui o heap em 1 de tamanho

		swap = unsorted_values[0];
		unsorted_values[0] = unsorted_values[size-1];
		unsorted_values[size-1] = swap;

		size--;

		// Garante a propriedade de heap
		max_heapfy(unsorted_values, 0, size);
	}

} // heapsort

// Recebe como parametros o vetor, o nodo atual e o tamanho do array que deve ser processado no heap
void max_heapfy (vector<generic_register> &unsorted_values, int current_node, int size)
{
	int left_son = current_node*2 + 1;
	int right_son = current_node*2 + 2;
	generic_register swap;

	// Se o filho a esquerda for maior que o pai, troca seus valores
	if (left_son < size && unsorted_values[current_node].key.compare(unsorted_values[left_son].key) < 0)
	{
		swap = unsorted_values[left_son];
		unsorted_values[left_son] = unsorted_values[current_node];
		unsorted_values[current_node] = swap;
		max_heapfy (unsorted_values, left_son, size);
	}

	// Se o filho a direita for maior que o pai, troca seus valores
	if (right_son < size && unsorted_values[current_node].key.compare(unsorted_values[right_son].key) < 0)
	{
		swap = unsorted_values[right_son];
		unsorted_values[right_son] = unsorted_values[current_node];
		unsorted_values[current_node] = swap;
		max_heapfy (unsorted_values, right_son, size);
	}

} // max_heapfy

void create_max_heap (vector<generic_register> &unsorted_values)
{
	int current_node;
	for (current_node = unsorted_values.size() - 1; current_node >= 0; current_node--)
	{
		max_heapfy (unsorted_values, current_node, unsorted_values.size());
	}
} // create_max_heap
