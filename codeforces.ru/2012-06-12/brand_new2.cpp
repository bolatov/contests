// brand_new2.cpp

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	int l_size;
	cin >> l_size;

	// printf("l_size: %d \n", l_size);

	vector<int> lesha(l_size, 0);
	unordered_map<string, int> w2n;
	for (int i=0; i < l_size; ++i) {
		string s;
		cin >> s;
		w2n[s] = i+1;
		lesha[i] = i+1;
	}

	int tasks;
	cin >> tasks;
	vector<vector<int>> archive(tasks);
	for (int i = 0; i < tasks; i++) {
		int numW;
		cin >> numW;	// = Integer.parseInt(args[++last]);
		vector<int> ivan(numW, 0);
		for (int j = 0; j < numW; j++) {
			string s;
			cin >> s;	// = args[++last];
			if (w2n.find(s) != w2n.end()) {
				int val = w2n[s];
				ivan[j] = val;
			} 
		}
		archive[i] = ivan;
	}

	int min_x = lesha.size()*lesha.size();
	int task_index = -1;

	do 
	{
		for (int i = 0; i < archive.size(); ++i)
		{
			vector<int> arch_task = archive[i];

			// test
			// cout << "arch_task: ";
			// for (int l = 0; l < arch_task.size(); ++l)
			// {
			// 	/* code */
			// 	cout << arch_task[l] << " ";
			// }
			// cout << endl;
			// end test
			// test
			// cout << "lesha: ";
			// for (int l = 0; l < lesha.size(); ++l)
			// {
			// 	/* code */
			// 	cout << lesha[l] << " ";
			// }
			// cout << endl;
			// end

			int k = 0;
			for (int j = 0; j< arch_task.size(); ++j)
			{
				if ( arch_task[j] == lesha[k] )
					k++;
				// if (k == lesha.size())
				// 	break;
			}

			// count inversions
			// cout << "k: " << k << endl;
			if (k >= lesha.size())
			{
				// cout << "\tyes, it is subarray: " << k << endl;
				// cout << "bindex = " << i+1 << endl;


				int invs = 0;
				for (int j = 0; j < lesha.size(); ++j)
				{
					for (k = j+1; k < lesha.size(); ++k)
					{
						if (lesha[j] > lesha[k])
							invs++;
					}
				}
				// cout << "before: min " << min_x << endl;
				if (invs == min_x && task_index > i+1)
				{
					task_index = i+1;
				}

				if (invs < min_x)
				{
					min_x = invs;
					task_index = i+1;
				}
				// cout << "after: min " << min_x << endl;
				// cout << "aindex = " << task_index << endl;
			}
			// cout << endl;
		}
	} while ( next_permutation(lesha.begin(), lesha.end()));

	if (task_index == -1) {
		cout << "Brand new problem!" << endl;
	} else {
		cout << task_index << endl;
		int n = lesha.size();
		int p = n * (n-1)/2 - min_x + 1;
		cout << "[:";
		for (int i=0; i<p; i++) {
			cout << "|";
		}
		cout << ":]" << endl;
	}
}
