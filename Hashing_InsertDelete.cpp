#include <iostream>
#include <vector>
#include <list>

class HashTableExample
{
	int bucket_size;
	std::list<int>* hash_table;
public:
	HashTableExample(int size):bucket_size(size){
	
		hash_table = new std::list<int>[bucket_size];
	}
	int hash_function(int x)
	{
		return(x % bucket_size);
	}
	~HashTableExample()
	{
		if (hash_table)
		{
			delete[]hash_table;
			hash_table = nullptr;
		}
	}
	void insert_element(int data);
	void delete_element(int data);
	void display();
};

void HashTableExample::insert_element(int data)
{
	int index = hash_function(data);
	hash_table[index].push_back(data);
}

void HashTableExample::delete_element(int data)
{
	//Get the index of element
	int index = hash_function(data);

	//Traverse the bucket only where data present in index
	std::list<int>::iterator i;
	for (i = hash_table[index].begin(); i != hash_table[index].end(); i++)
	{
		if (*i == data)
		{
			break;
		}
	}

	if (i != hash_table[index].end())
	{
		hash_table[index].erase(i);
	}
}

void HashTableExample::display()
{
	for (auto i = 0; i < bucket_size; i++)
	{
		std::cout << "bucket[" << i << "]" <<":";
		for (auto x : hash_table[i])
		{
			std::cout << x << "-->";
		}
		std::cout << std::endl;
	}
}

int main()
{
	std::vector<int> myArr{ 15, 11, 27, 8, 12 };
	HashTableExample hashObj(7); //7 buckets in hash table

	for (auto x : myArr)
	{
		hashObj.insert_element(x);
	}
	hashObj.display();

	std::cout << "Delete 11 from list" << std::endl;
	hashObj.delete_element(11);
	hashObj.display();
	return 0;
}