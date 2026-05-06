#include <utility>
#include <iostream>
#include <optional>
#include <vector>

using namespace std;

template<typename T>
optional<vector<T>>
bubble_sort(vector<T>& vec)
{
    if (vec.size() ==0) {
        return {};
    }
    for (int i=0; i< vec.size()-1; i =i+1 ){
        for (int j= vec.size()-1; j>i; j=j-1) {
            if (vec[j]<vec[j-1]){
                swap(vec[j],vec[j-1]);

            }
        }
    }
    return vec;
}

template<typename T>
optional<vector<T>>
insertion_sort(vector<T>& vec)
{
    if (vec.size() ==0) {
        return {};
    }
     for (int j=1; j<=vec.size()-1; j =j+1 ){
        T key=vec[j];
        int i=j-1;

        while (i>=0 && vec[i]>key) {
            swap(vec[i+1], vec[i]);
            i = i-1;
        }
        vec[i+1] = key;
    }
    return vec;
}


template<typename T>
optional<vector<T>>
selection_sort(vector<T>& vec)
{
    if (vec.size() ==0) {
        return {};
    }
     for (int i=0; i<= vec.size()-2; i =i+1 ){
        int min = i;
        for (int j=i+1 ; j<=vec.size()-1; j = j+1) {
            if (vec[j]<vec[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(vec[i],vec[min]);
        } 
    }
    return vec;
}

template<typename T>
optional<vector<T>>
merge(vector<T>& vec, int p, int q, int r){
    int n1= q-p+1;
    int n2 = r-q;
    vector<T> L(n1+1);
    vector<T> R(n2+1);
    for (int i=0; i< n1; i = i+1){
        L[i]= vec[p+i];
    }
    for (int j=0; j<n2; j = j+1){
        R[j]= vec[q+1+j];
    }
    int j=0;
    int i=0; //parto da 0 e non da 1 per non avere errori di off-by-one
    for (int k=p; k<=r; k=k+1){
         if (i < n1 && (j >= n2 || L[i] <= R[j])) {
        vec[k] = L[i];
        i=i+1;  
        } 
         else {
        vec[k] = R[j];
        j=j+1;
        }
    }
    return vec;
}

template<typename T>
optional<vector<T>>
merge_sort(vector<T>& vec, int p, int r)
{
    if (vec.size() ==0) {
        return {};
    }
    if (p < r) {
        int q = (p+r)/2;
        merge_sort(vec, p, q);
        merge_sort(vec, q+1, r);
        merge(vec,p,q,r);
    }
    return vec;
}

template<typename T>
int partition(vector<T>& vec, int p, int r){
    T x = vec[r];
    int i = p-1;
    for (int j=p; j<r; j = j+1){
        if (vec[j]<=x){
            i = i+1;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i+1], vec[r]);
    return i+1;
}

template<typename T>
optional<vector<T>>
quick_sort(vector<T>& vec, int p, int r){
    if (p < r) {
        int q = partition(vec,p,r);
        quick_sort(vec,p,q-1);
        quick_sort(vec,q+1,r);
    }
    return vec;
}

//dai test fatti in measure_sort.cpp, noto  che sotto il 

template<typename T>
bool is_sorted(const vector<T>& vec){
    if (vec.size()==0){
        return true;
    }

    for(int i=0 ; i < vec.size()-1; i = i+1){
        if (vec[i]>vec[i+1]){
            return false;
        }
    }
    return true;
}

//il quicksort sotto una certa soglia (dimensione circa 40/44) è più lento dell'insertionsort quindi implemento un quicksort modificato che utilizzi l'insertionsort prima di quella soglia e il quicksort dopo
template<typename T>
optional<vector<T>>
//implemento un nuovo insertion che ordini 'a pezzi'
insertion_new(vector<T>& vec, int p, int r)
{    if (vec.size()==0) {
        return{};
    }
    for ( int i=p+1; i<=r; i++) {
        T value=vec[i];
        int j=i-1;
        while (j>=p && vec[j]>value) {
            swap(vec[j+1],vec[j]);
            j=j-1;
        }
        vec[j+1]=value;
    
    }

}

template<typename T>
optional<vector<T>>
quick_insertion_sort(vector<T>& vec, int p, int r, int soglia = 40)
{
    if (vec.size()==0) {
        return {};
    }
    if (p < r)
    {
        if ((r-p+1) < soglia) {
            insertion_new(vec,p,r);
        } 
        else {
            int q = partition(vec, p, r);
            quick_insertion_sort(vec,p,q-1,soglia);
            quick_insertion_sort(vec,q+1,r,soglia);
        }
    }
    return vec;
}