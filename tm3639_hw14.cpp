#include <iostream>
#include <string>
#include <vector>
using namespace std;

//driver
void recursive_min_max(vector<int>& param_vector);
//first overloaded min max
void recursive_min_max(vector<int>& param_vector, int param_index_zero, int param_index_one);
//second overloaded min max
void recursive_min_max(vector<int>& param_vector, int param_min, int param_max);


//first merge sort declaration
void merge_sort(vector<int>& param_vector, int param_start, int param_end);
//second merge sort declaration
void merge_sort(vector<int>& param_vector, int param_start, int param_mid_index, int param_end);

//first merge_sort definition
void merge_sort(vector<int>& param_vector, int param_start, int param_end){
    if(param_start < param_end){
        int mid_index = (param_start + param_end)/2;

        merge_sort(param_vector,param_start, mid_index);//first half
        merge_sort(param_vector, mid_index + 1, param_end);//second half

        merge_sort(param_vector, param_start, mid_index, param_end);
    }
}
//second merge_sort definition
void merge_sort(vector<int>& param_vector, int param_start, int param_mid_index, int param_end){
    int rhv_start= param_mid_index + 1;
    int lhv_size = param_mid_index - param_start + 1;
    int rhv_size = param_end - param_mid_index + 1;

    vector<int> LH_VECTOR;
    vector<int> RH_VECTOR;

    //fill array

    for(int i = 0; i < lhv_size;i++){
        LH_VECTOR.push_back(param_vector[param_start]);
    }


    for(int i = 0; i < rhv_size;i++){
        RH_VECTOR.push_back(param_vector[rhv_start+i]);
    }

    int lhv_iterator=0;
    int rhv_iterator =0;

    int og_index = param_start;

    while(lhv_iterator<lhv_size && rhv_iterator<rhv_size)
    {

        if(LH_VECTOR[lhv_iterator] < RH_VECTOR[rhv_iterator])
        {
            param_vector[og_index]= LH_VECTOR[lhv_iterator];
            lhv_iterator++;
        }
        else
        {
            param_vector[og_index]=RH_VECTOR[rhv_iterator];
            rhv_iterator++;
        }
        og_index++;

        while(lhv_iterator<lhv_size){
            param_vector[og_index] = LH_VECTOR[lhv_iterator];
            lhv_iterator++;
            og_index++;
        }
        while(rhv_iterator<rhv_size){
            param_vector[og_index] = RH_VECTOR[rhv_iterator];
            rhv_iterator++;
            og_index++;
        }


    }
}


void recursive_min_max(vector<int>& param_vector){
    unsigned int index_a, index_b, n_size, start_point;
    index_a = param_vector.at(0);
    index_b = param_vector.at(1);

    n_size = param_vector.size();//size of array
    start_point =0;


    if(param_vector.size()<=0){
        cout<< " Error: You entered an empty array!";
    }
    else if (param_vector.size() == 1){
        cout << param_vector.at(0);
    }
    else
    { //merge sort
        merge_sort( param_vector, start_point, n_size);

        //the first call to min max with overloaded params
        recursive_min_max(param_vector, index_a, index_b);
    }
}




int main(){

    vector<int> list_of_numbers = {1,2,3,4};
    recursive_min_max(list_of_numbers);


    return 0;
}



void recursive_min_max(vector<int>& param_vector, int param_index_zero, int param_index_one){
    int min = param_index_zero;
    int max = param_index_one;
    if(param_vector.size()  > 1 ) {//remember, you added this in the 11th hour because of an out of range alert, didnt test yet
        if (param_vector.at(0) < param_vector.at(1)) {


            cout << " " << min << " " << max ;
        }

        //this is the second call to a newly overloaded min max function
        recursive_min_max(param_vector, param_vector[min+1], param_vector[max + 1]);
    }
}



/*finds the min and max with a hard coded sequential array
 *
 * //driver
void recursive_min_max(vector<int>& param_vector);
//first overloaded min max
void recursive_min_max(vector<int>& param_vector, int param_index_zero, int param_index_one);
//second overloaded min max
void recursive_min_max(vector<int>& param_vector, int param_min, int param_max);
//driver definition
void recursive_min_max(vector<int>& param_vector){
    int index_a, index_b;
    index_a = param_vector.at(0);
    index_b = param_vector.at(1);
    if(param_vector.size()<=0){
        cout<< " Error: You entered an empty array!";
    }
    else if (param_vector.size() == 1){
        cout << param_vector.at(0);
    }
    else
    {      //the first call to min max with overloaded params
        recursive_min_max(param_vector, index_a, index_b);
    }
}

void recursive_min_max(vector<int>& param_vector, int param_index_zero, int param_index_one){
    int min = param_index_zero;
    int max = param_index_one;
    if(param_vector.size() >1 ) {
        if (param_vector.at(0) < param_vector.at(1)) {


            cout << " " << min << " " << max ;
        }

        //this is the second call to a newly overloaded min max function
        recursive_min_max(param_vector, param_vector[min+1], param_vector[max + 1]);
    }
}



int main(){

    vector<int> list_of_numbers = {1,2,3,4,5,6,7,8,9,10};
    recursive_min_max(list_of_numbers);

    return 0;
}

*/