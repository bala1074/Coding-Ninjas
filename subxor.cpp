#include <bits/stdc++.h>
#define MAX 31

using namespace std;

class TrieNode
{
public:
	int value;
	TrieNode *left;
	TrieNode *right;

	void insert(int n)
	{
		TrieNode *curr = this;
		for (int i = MAX; i >= 0; i--)
		{
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
		curr->value = n;
	}
};

int query(TrieNode *root, int pre_xor, int k)
{
	if (root->left == NULL and root->right == NULL)
	{
		cout << root->value << endl;
		if (root->value < k)
		{
			return 1;
		}
	}

	int count = 0;
	if (root->left)
	{
		// cout << "left\n";
		count += query(root->left, k);
	}
	if (root->right)
	{
		// cout << "right\n";
		count += query(root->right, k);
	}

	return count;
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
	