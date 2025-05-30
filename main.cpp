#include <iostream>
#include <vector>
#include <cstdlib>   
#include <ctime> 
using namespace std;

int arreglo[10]={0,1,2,3,4,5,6,7,8,9};
int temp,minimo, num, length, menu;

vector<int> BubbleSort(vector<int> array){
    length=array.size();
    for(int Gus=0;Gus<length;Gus++){
        for(int Pou=0;Pou<length;Pou++){
            if(array[Pou]>array[Pou+1]){
                temp=array[Pou];
                array[Pou]=array[Pou+1];
                array[Pou+1]=temp;
            }
        }
    }
 return array;
}

vector<int> QuickSort(vector<int> array){
    length = array.size();
    int low = 0, high = length - 1;
    vector<int> stack(high - low + 1);
    int top = -1;
    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];
        int pivot = array[high];
        int Gus = low - 1;

        for (int Pou = low; Pou < high; Pou++) {
            if (array[Pou] <= pivot) {
                Gus++;
                temp = array[Gus];
                array[Gus] = array[Pou];
                array[Pou] = temp;
            }
        }
        temp = array[Gus + 1];
        array[Gus + 1] = array[high];
        array[high] = temp;
        int pi = Gus + 1;

        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }
        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
    return array;
}

vector<int> HeapSort(vector<int> array){
    length = array.size();
    for (int Gus = length / 2 - 1; Gus >= 0; Gus--) {
        int raiz = Gus;
        while (2 * raiz + 1 < length) {
            int child = 2 * raiz + 1;
            if (child + 1 < length && array[child] < array[child + 1])
                child++;
            if (array[raiz] < array[child]) {
                temp = array[raiz];
                array[raiz] = array[child];
                array[child] = temp;
                raiz = child;
            } else break;
        }
    }

    for (int Gus = length - 1; Gus > 0; Gus--) {
        temp = array[0];
        array[0] = array[Gus];
        array[Gus] = temp;
        int raiz = 0;
        while (2 * raiz + 1 < Gus) {
            int child = 2 * raiz + 1;
            if (child + 1 < Gus && array[child] < array[child + 1])
                child++;
            if (array[raiz] < array[child]) {
                temp = array[raiz];
                array[raiz] = array[child];
                array[child] = temp;
                raiz = child;
            } else break;
        }
    }
    return array;
}

vector<int> MergeSort(vector<int> array,int izq, int der){
    length=array.size();
    if(izq>=der){
        return array;
    }
    num = izq +(der+izq)/2;
    MergeSort(array,izq,num);
    MergeSort(array,num+1,der);
    int n1=num-izq+1;
    int n2=der-num;
    vector<int> Izq(n1), Der(n2);
        for (int Gus = 0; Gus < n1; Gus++)
        Izq[Gus] = array[izq + Gus];
    for (int Pou = 0; Pou < n2; Pou++)
        Der[Pou] = array[num + 1 + Pou];

    int G = 0, P = 0, A = izq;
    while (G < n1 && P < n2) {
        if (Izq[G] <= Der[P]) {
            array[A++] = Izq[P++];
        } else {
            array[A++] = Der[P++];
        }
    }

    while (G < n1){
        array[A++] = Izq[G++];
    } 
    while (P < n2){
         array[A++] = Der[P++];
    }
    return array;
}

vector<int> SelectionSort(vector<int>array){
    length=array.size();
    for(int Gus=0;Gus<length;Gus++){
        minimo = Gus;
        for(int Pou=Gus+1;Pou<length;Pou++){
            if(array[Pou]<array[minimo]){
                minimo=Pou;
            }
        }
        temp=array[Gus];
        array[Gus]=array[minimo];
        array[minimo]=temp;
    }
 return array;
}

vector<int> InsertSort(vector<int> array){
    length=array.size();
     for(int Gus=0;Gus<length;Gus++){
        num=Gus;
        while(num>0 && (array[num] && array[num-1])){
            temp=array[num];
            array[num]=array[num-1];
            array[num-1]=temp;
            num--;
        }
     }
 return array;
}

vector<int> llenarVector(int cantidad) {
    vector<int> array(cantidad);
    srand(time(nullptr));  

    for (int Gus = 0; Gus < cantidad; Gus++) {
        array[Gus] = 1 + rand() % (1,000,000,000 - 0 + 1);
    }

    return array;
}

int main(){
 vector<int> Prueba = llenarVector(5000);
 cout<< " 1. BubbleSort \n 2. QuickSort \n 3. HeapSort \n 4. MergeSort \n 5. SelectionSort \n 6. InsertionSort\n";
 cin >> menu;
 clock_t inicio, fin;
 double tiempo;

    switch (menu) {
        case 1: {
            inicio = clock();
            BubbleSort(Prueba);
            fin = clock();     
            tiempo = double(fin - inicio) * 1000.0 / CLOCKS_PER_SEC;  
            cout << "Tiempo de ejecución: " << tiempo << " ms" << endl;
            break;
        }
        case 2: {
            inicio = clock();
            QuickSort(Prueba);
            fin = clock();     
            tiempo = double(fin - inicio) * 1000.0 / CLOCKS_PER_SEC;  
            cout << "Tiempo de ejecución: " << tiempo << " ms" << endl;
            break;
        }
        case 3: {
            inicio = clock();
            HeapSort(Prueba);
            fin = clock();     
            tiempo = double(fin - inicio) * 1000.0 / CLOCKS_PER_SEC;  
            cout << "Tiempo de ejecución: " << tiempo << " ms" << endl;
            break;
        }
        case 4: {
            inicio = clock();
            MergeSort(Prueba, 0, Prueba.size() - 1);
            fin = clock();     
            tiempo = double(fin - inicio) * 1000.0 / CLOCKS_PER_SEC;  
            cout << "Tiempo de ejecución: " << tiempo << " ms" << endl;
            break;
        }
        case 5: {
            inicio = clock();
            SelectionSort(Prueba);
            fin = clock();     
            tiempo = double(fin - inicio) * 1000.0 / CLOCKS_PER_SEC;  
            cout << "Tiempo de ejecución: " << tiempo << " ms" << endl;
            break;
        }
        case 6: {
            inicio = clock();
            InsertSort(Prueba);
            fin = clock();     
            tiempo = double(fin - inicio) * 1000.0 / CLOCKS_PER_SEC;  
            cout << "Tiempo de ejecución: " << tiempo << " ms" << endl;
            break;
        }
        default:
            cout << "Opción no válida" << endl;
            break;
    }

}