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