/* 桶排序

function bucketSort(array, k) is
  buckets <- new array of k empty lists
  M <- the maximum key value in the array
  for i = 1 to length(array) do
    insert array[i] into buckets[floor(k * array[i] / M)]
  for i = 1 to k do
    nextSort(buckets[i])
  return the concatenation of buckets[1], ...., buckets[k]

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void bksort(float A[], int l, int h)
{
    int           size = h - l;
    vector<float> b[size]; //这里分配size个桶，但桶大小不需要保证一定是size

    //将元素A[i]放置在对应桶中
    for (int i = l; i < h; i++) {
        //桶的区间分配根据实际情况定
        //因为A[i]都是0~1之间，所以这里用 int(size * A[i])
        int bi = size * A[i];
        b[bi].push_back(A[i]);
    }

    for (int i = 0; i < size; i++) {
        sort(b[i].begin(), b[i].end()); //桶内排序
    }
    int idx = l; //指向数组A的下标

    for (int i = 0; i < size; i++) {            //遍历桶
        for (int j = 0; j < b[i].size(); j++) { //遍历桶内元素
            A[idx++] = b[i][j];
        }
    }
}

int main()
{
    float A[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};

    bksort(A, 0, 9);

    for (auto &i : A) {
        cout << i << " ";
    }
}
