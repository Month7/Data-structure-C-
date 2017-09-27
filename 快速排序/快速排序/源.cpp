#include <stdio.h>
void quick_sort(int s[], int m, int n) {
	int i, j, x;

	if (m < n) {
		i = m;
		j = n;
		x = s[i];
		while (i < j) {
			while (i < j&&s[j] > x) {
				j--;
			}
			if (i < j) {
				s[i] = s[j];
				i++;
			}
			while (i < j&&s[i] < x) {
				i++;
			}
			if (i < j) {
				s[j] = s[i];
				j--;
			}
		}
		s[i] = x;
		quick_sort(s, m + 1, n);
		quick_sort(s, m, n - 1);
	}
}
int main() {
	int a[] = { 49,38,65,97,76,13,27 };
	int l = 0;
	int r = 6;
	quick_sort(a, 0, 6);

	for (int i = 0; i <= r; i++)
		printf("%4d", a[i]);
	return 0;
}