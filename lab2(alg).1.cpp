#include<algorithm>
#include<math.h>
#include<time.h>
#include<iostream>
#include <random>

using namespace std;

struct snails {
	double x;
	double y;
};

struct Generator {
	int random_x;
	int random_y;
};

Generator random_x() {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> point(0, 100000);
	int random_x = point(mt);
	struct Generator Gen_point;
	Gen_point.random_x = random_x;
	return Gen_point;
}

Generator random_y() {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> point(0, 100000);
	int random_y = point(mt);
	struct Generator Gen_point;
	Gen_point.random_y = random_y;
	return Gen_point;
}

const int N = 10000000;

bool compare_x(const snails& snail1, const snails& snail2) { 
	return snail1.x < snail2.x || snail1.x == snail2.x && snail1.y < snail2.y;
}

bool compare_y(const snails& snail1, const snails& snail2) { 
	return snail1.y < snail2.y;
}

double min_dist;

int min_distance(const snails& snail1, const snails& snail2) {
	double dist = sqrt((snail1.x - snail2.x) * (snail1.x - snail2.x) + (snail1.y - snail2.y) * (snail1.y - snail2.y));
	if (dist < min_dist) {
		min_dist = dist;
		return 2;
	}
	else
		if (dist == min_dist) 
			return 1;
		else
			return 0;
}

snails snail[N];
snails t[N];
bool confused = false;
int same_dist = 0;

void find_min_dist(int l_snail, int r_snail) {

	if (r_snail - l_snail <= 3) {
		for (int i = l_snail; i <= r_snail; ++i) {
			for (int j = i + 1; j <= r_snail; ++j)
				if (min_distance(snail[i], snail[j]) == 1)
					same_dist++;
			if (same_dist > 0)
				confused = true;
			else
				confused = false;
		}
		sort(snail + l_snail, snail + r_snail + 1, &compare_y);
		return;
	}

	int mid = (l_snail + r_snail) >> 1;
	int mid_x = snail[mid].x;
	find_min_dist(l_snail, mid);
	double min_dist_l = min_dist;
	find_min_dist(mid + 1, r_snail);
	double min_dist_r = min_dist;
	double min_r_l = min(min_dist_l, min_dist_r);
	if (min_r_l < min_dist)
		min_dist = min_r_l;

	int mid_area = 0;
	for (int i = l_snail; i <= r_snail; ++i) {
		same_dist = 0;
		if (abs(snail[i].x - mid_x) <= min_dist) {
			for (int j = mid_area - 1; j >= 0 && snail[i].y - t[j].y < min_dist; --j)
				if (min_distance(snail[i], t[j]) == 1)
					same_dist++;
			t[mid_area++] = snail[i];
		}
		if (same_dist > 0)
			confused = true;
		else
			confused = false;
	}
}

int main() {
	cout << "Enter number of snails: " << '\n';
	int num;
	cin >> num;

	if (num > N)
	{
		cout << "Too many snails.\n";
		return 0;
	}

	if (num == 1)
	{
		cout << "One sad alone snail.\n";
		return 0;
	}
	for (int i = 0; i < num; i++)
	{
		Generator rand_point_x = random_x();
		Generator rand_point_y = random_y();
		int random_x = rand_point_x.random_x;
		snail[i].x = random_x;
		int random_y = rand_point_y.random_y;
		snail[i].y = random_y;
		cout << snail[i].x << "   " << snail[i].y << "\n";
	}

	clock_t start, end;
	unsigned int time = clock();
	start = clock();
	sort(snail, snail + num, &compare_x);
	min_dist = 1E20;
	find_min_dist(0, num - 1);
	end = clock();
		if (confused == false) {
			if (min_dist == 0)
			{
				cout << "Distance = 0." << '\n';
				cout << "Algorithm running time: " << ((double)end - start) / ((double)CLOCKS_PER_SEC) << " seconds\n";
				return 0;;
			}
			cout << "Min distance: " << min_dist << '\n';
			double min_time = min_dist / 2;
			cout << "Answer (time in sec): " << min_time << " \n(time = min_dist / 2 - because snails crawl towards each other) " << '\n';
			cout << "Algorithm running time: " << ((double)end - start) / ((double)CLOCKS_PER_SEC) << " seconds\n";
		}

		else
			cout << "Snails can't choose (confused)." << '\n';
	return 0;
}