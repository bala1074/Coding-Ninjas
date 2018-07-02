#include <bits/stdc++.h>
#define MAX 31

using namespace std;

class TrieNode
{
public:
	int count = 0;
	TrieNode *left;
	TrieNode *right;

	void insert(int n)
	{
		TrieNode *curr = this;
		for (int i = MAX; i >= 0; i--)
		{
			curr->count++;
			int b = ((n >> i) & 1);

			if (b == 0)
			{
				if (!curr->left)
				{
					curr->left = new TrieNode();
				}
				curr = curr->left;
			}
			else
			{
				if (!curr->right)
				{
					curr->right = new TrieNode();
				}
				curr = curr->right;
			}
		}
	}
};

int query(TrieNode *root, int pre_xor, int k)
{
	TrieNode *curr = root;
	int finalCount = 0;
	for (int i = MAX; i >= 0; i--)
	{
		int bit_k = ((k >> i) & 1);
		int bit_p = ((pre_xor >> i) & 1);

		if (bit_k == 0)
		{
			if (bit_p == 0)
			{
				if (curr->left)
				{
					curr = curr->left;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (curr->right)
				{
					curr = curr->right;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			if (bit_p == 0)
			{
				finalCount += curr->left->count;
				curr->left->count = 0;
				if (curr->right)
				{
					curr = curr->right;
				}
				else
				{
					break;
				}
			}
			else
			{
				finalCount += curr->right->count;
				curr->right->count = 0;
				if (curr->left)
				{
					curr = curr->left;
				}
				else
				{
					break;
				}
			}
		}
	}

	return finalCount;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,k;
		cin >> n >> k;
		int *arr = new int[n]();
		int result = INT_MIN;
		int pre_xor = 0;
		TrieNode *root = new TrieNode();
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			pre_xor ^= arr[i];
			root->insert(pre_xor);

			count += query(root, pre_xor, k);
		}

		cout << count << endl;
		delete root;
	}

	return 0;
}
	