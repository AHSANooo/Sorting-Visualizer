#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

const int resolutionX = 1472;
const int resolutionY = 1280;
const int boxPixelsX = 32;
const int boxPixelsY = 32;
const int Rows = resolutionY / boxPixelsX;
const int Cols = resolutionX / boxPixelsY;




int Grid[Rows][Cols] = {};



const int elements = 36;
int clicks = 0;

//initialization title bar

sf::RenderWindow window(sf::VideoMode(resolutionX, resolutionY), "Sorting Visualizer by Ahsan", sf::Style::Close | sf::Style::Titlebar);

sf::RectangleShape newArrayButton(sf::Vector2f(200, 50));
sf::RectangleShape bubbleSortButton(sf::Vector2f(200, 50));
sf::RectangleShape quickSortButton(sf::Vector2f(200, 50));
sf::RectangleShape heapSortButton(sf::Vector2f(200, 50));
sf::RectangleShape mergeSortButton(sf::Vector2f(200, 50));

sf::RectangleShape newArrayButton2(sf::Vector2f(200, 50));
sf::RectangleShape bubbleSortButton2(sf::Vector2f(200, 50));
sf::RectangleShape quickSortButton2(sf::Vector2f(200, 50));
sf::RectangleShape heapSortButton2(sf::Vector2f(200, 50));
sf::RectangleShape mergeSortButton2(sf::Vector2f(200, 50));


sf::Text newArrayText;
sf::Text bubbleSortText;
sf::Text quickSortText;
sf::Text mergeSortText;
sf::Text heapSortText;


sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;


//functions prototypes


void drawButtons(sf::Text& newArrayText, sf::Text& bubbleSortText,sf::Text& quickSortText, sf::Text& mergeSortText , sf::Text& heapSortText);
void generateRandomArray(int*& arr,int *&sarr);
void bubbleSort(int*& arr,int*&sarr);
void handleButtonClick(int*& arr,int *&sortedArray);
void swap(int& a, int& b);
void quickSort(int *&arr,int start,int end,int *&sarr);
int separator(int arr[],int start,int end, int*&sarr);
void mergeSort(int arr[], int left, int right, int sortedArray[]);
void merge(int arr[], int left, int mid, int right, int sortedArray[]);
void heapSort(int arr[], int n, int sortedArray[]);
void heapify(int arr[], int n, int i, int sortedArray[]);



int main() {
    srand(time(0));


    window.setSize(sf::Vector2u(1920, 1015));
    window.setPosition(sf::Vector2i(0, 0));

    backgroundTexture.loadFromFile("Textures/background.png");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setColor(sf::Color(255, 255, 255, 255 * 0.45));

    sf::Font font;
    font.loadFromFile("Fonts/arial.ttf");

    sf::Text startingText;
    startingText.setFont(font);
    startingText.setCharacterSize(36);
    startingText.setFillColor(sf::Color::White);
    startingText.setPosition(500, 500);
    startingText.setString("Sorting Visualizer by Ahsan \nStarting... ");


    window.clear();
    window.draw(startingText);
    window.display();
    sf::sleep(sf::seconds(1));


    int* arr = new int[elements];
    int * sortedArray = new int [elements];
    


    newArrayButton.setPosition(50, resolutionY - 100);
    newArrayButton.setFillColor(sf::Color::Green);

    bubbleSortButton.setPosition(300, resolutionY - 100);
    bubbleSortButton.setFillColor(sf::Color::Green);
    
    quickSortButton.setPosition(550, resolutionY - 100);
    quickSortButton.setFillColor(sf::Color::Green);
    
    mergeSortButton.setPosition(800, resolutionY - 100);
    mergeSortButton.setFillColor(sf::Color::Green);
    
    heapSortButton.setPosition(1050, resolutionY - 100);
    heapSortButton.setFillColor(sf::Color::Green);
    
    
    
    newArrayButton2.setPosition(50, resolutionY - 100);
    newArrayButton2.setFillColor(sf::Color::Magenta);

    bubbleSortButton2.setPosition(300, resolutionY - 100);
    bubbleSortButton2.setFillColor(sf::Color::Magenta);

    quickSortButton2.setPosition(550, resolutionY - 100);
    quickSortButton2.setFillColor(sf::Color::Magenta);
    
    mergeSortButton2.setPosition(800, resolutionY - 100);
    mergeSortButton2.setFillColor(sf::Color::Magenta);
    
    heapSortButton2.setPosition(1050, resolutionY - 100);
    heapSortButton2.setFillColor(sf::Color::Magenta);



    newArrayText.setFont(font);
    newArrayText.setCharacterSize(20);
    newArrayText.setFillColor(sf::Color::Black);
    newArrayText.setPosition(70, resolutionY - 90);
    newArrayText.setString("New Array");


    bubbleSortText.setFont(font);
    bubbleSortText.setCharacterSize(20);
    bubbleSortText.setFillColor(sf::Color::Black);
    bubbleSortText.setPosition(320, resolutionY - 90);
    bubbleSortText.setString("Bubble Sort");
    
    quickSortText.setFont(font);
    quickSortText.setCharacterSize(20);
    quickSortText.setFillColor(sf::Color::Black);
    quickSortText.setPosition(570, resolutionY - 90);
    quickSortText.setString("Quick Sort");
    
    mergeSortText.setFont(font);
    mergeSortText.setCharacterSize(20);
    mergeSortText.setFillColor(sf::Color::Black);
    mergeSortText.setPosition(820, resolutionY - 90);
    mergeSortText.setString("Merge Sort");
    
    heapSortText.setFont(font);
    heapSortText.setCharacterSize(20);
    heapSortText.setFillColor(sf::Color::Black);
    heapSortText.setPosition(1070, resolutionY - 90);
    heapSortText.setString("Heap Sort");
    
    

	
    int temp = 0;
    window.clear();

    while (window.isOpen()) {
        drawButtons(newArrayText, bubbleSortText,quickSortText, mergeSortText , heapSortText);

        window.draw(backgroundSprite);

        if (temp == 0)
            generateRandomArray(arr, sortedArray);
        temp++;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                // Increment clicks and handle button click
                clicks++;
                handleButtonClick(arr, sortedArray);
            }
        }

       

        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                return 0;
            }
        }


    }

    delete[] arr;

    return 0;
}
void drawButtons(sf::Text& newArrayText, sf::Text& bubbleSortText,sf::Text& quickSortText, sf::Text& mergeSortText , sf::Text& heapSortText) {


    	switch (clicks){
    
    	        
    	        case 1:
    	        window.draw(newArrayButton2);
    		window.draw(newArrayText);
    		window.draw(bubbleSortButton);
    		window.draw(bubbleSortText);
    		window.draw(quickSortButton);
    		window.draw(quickSortText);
    		window.draw(mergeSortButton);
    		window.draw(mergeSortText);
    		window.draw(heapSortButton);
    		window.draw(heapSortText);
    	        
    	        break;
    	        
      	        case 2:
      	        window.draw(newArrayButton);
    		window.draw(newArrayText);
    		window.draw(bubbleSortButton2);
    		window.draw(bubbleSortText);
    		window.draw(quickSortButton);
    		window.draw(quickSortText);
    		window.draw(mergeSortButton);
    		window.draw(mergeSortText);
    		window.draw(heapSortButton);
    		window.draw(heapSortText);
      	        
    	        break;
    	        
    	        case 3:
    	        window.draw(newArrayButton2);
    		window.draw(newArrayText);
    		window.draw(bubbleSortButton);
    		window.draw(bubbleSortText);
    		window.draw(quickSortButton);
    		window.draw(quickSortText);
    		window.draw(mergeSortButton);
    		window.draw(mergeSortText);
    		window.draw(heapSortButton);
    		window.draw(heapSortText);
    	        
    	        break;
    	        
    	        case 4:
    	        window.draw(newArrayButton);
    		window.draw(newArrayText);
    		window.draw(bubbleSortButton);
    		window.draw(bubbleSortText);
    		window.draw(quickSortButton2);
    		window.draw(quickSortText);
    		window.draw(mergeSortButton);
    		window.draw(mergeSortText);
    		window.draw(heapSortButton);
    		window.draw(heapSortText);
    	        
    	        break;
    	        
    	        case 5:
    	        window.draw(newArrayButton2);
    		window.draw(newArrayText);
    		window.draw(bubbleSortButton);
    		window.draw(bubbleSortText);
    		window.draw(quickSortButton);
    		window.draw(quickSortText);
    		window.draw(mergeSortButton);
    		window.draw(mergeSortText);
    		window.draw(heapSortButton);
    		window.draw(heapSortText);
    	        
    	        break;
    	        
      	        case 6:
      	        window.draw(newArrayButton);
    		window.draw(newArrayText);
    		window.draw(bubbleSortButton);
    		window.draw(bubbleSortText);
    		window.draw(quickSortButton);
    		window.draw(quickSortText);
    		window.draw(mergeSortButton2);
    		window.draw(mergeSortText);
    		window.draw(heapSortButton);
    		window.draw(heapSortText);
      	        
    	        break;
    	        
    	        case 7:
    	        window.draw(newArrayButton2);
    		window.draw(newArrayText);
    		window.draw(bubbleSortButton);
    		window.draw(bubbleSortText);
    		window.draw(quickSortButton);
    		window.draw(quickSortText);
    		window.draw(mergeSortButton);
    		window.draw(mergeSortText);
    		window.draw(heapSortButton);
    		window.draw(heapSortText);
    	        
    	        break;
    	        
    	        case 8:
    	        window.draw(newArrayButton);
    		window.draw(newArrayText);
    		window.draw(bubbleSortButton);
    		window.draw(bubbleSortText);
    		window.draw(quickSortButton);
    		window.draw(quickSortText);
    		window.draw(mergeSortButton);
    		window.draw(mergeSortText);
    		window.draw(heapSortButton2);
    		window.draw(heapSortText);
    	        
    	        break;
    	        
    	    default:
    	        
    	        window.draw(newArrayButton);
    		window.draw(newArrayText);
    		window.draw(bubbleSortButton);
    		window.draw(bubbleSortText);
    		window.draw(quickSortButton);
    		window.draw(quickSortText);
    		window.draw(mergeSortButton);
    		window.draw(mergeSortText);
    		window.draw(heapSortButton);
    		window.draw(heapSortText);
    	
    	}	

}

void generateRandomArray(int*& arr,int *&sortedArray) {

	
    for (int i = 0; i < elements; i++) {
    
        arr[i] = rand() % 23 + 2;
        
        			sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[i]));
               	     		rect.setPosition(i * boxPixelsX +boxPixelsX *5 , resolutionY - boxPixelsY * arr[i] -boxPixelsX *5);
               	     		rect.setFillColor(sf::Color::Yellow);
               	     		window.draw(rect);
               	     		
               	window.display();

                
                sf::sleep(sf::milliseconds(30));
                
                
     
        
    }
    
    for (int i = 0; i < elements; i++) {
    
    	sortedArray[i]=arr[i];
    
    
    }
    
    int n=elements;
    
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            
            if (sortedArray[j] > sortedArray[j + 1]) {
                
                swap(sortedArray[j], sortedArray[j + 1]);
                
                }
    
	}
    
    }
    
}    

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int*& arr,int *&sortedArray) {
    
    
    int n = elements;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            
            
            if (arr[j] > arr[j + 1]) {
                
                

                swap(arr[j], arr[j + 1]);

               
                window.clear();
                
                
                
                
                if(j!=elements-2 && j!=elements-1){
                    
                    
               			
     	 	 		sf::RectangleShape rect1(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[j+1]));
               	     		rect1.setPosition((j+1) * boxPixelsX +boxPixelsX *5 , resolutionY - boxPixelsY * arr[j+1] -boxPixelsX *5);
               	     		rect1.setFillColor(sf::Color::Red);
               	     		window.draw(rect1);
               	     		
               	    		sf::RectangleShape rect2(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[j+2]));
               	     		rect2.setPosition((j+2) * boxPixelsX +boxPixelsX *5 , resolutionY - boxPixelsY * arr[j+2] -boxPixelsX *5);
               	     		rect2.setFillColor(sf::Color::Red);
               	     		window.draw(rect2);
                    		
                    }else{
                    
                    
             		        sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[j+1]));
               	     		rect.setPosition((j+1) * boxPixelsX +boxPixelsX *5 , resolutionY - boxPixelsY * arr[j+1] -boxPixelsX *5);
               	     		rect.setFillColor(sf::Color::Yellow);
               	     		window.draw(rect);
                    
                    
                    
                    }
                
                
                
                window.draw(backgroundSprite);
                drawButtons(newArrayText, bubbleSortText,quickSortText, mergeSortText , heapSortText);

                for (int k = 0; k < elements; ++k) {
                    
                    
                    if(arr[k]==sortedArray[k]){
                    
                    
            		        sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[k]));
               	     		rect.setPosition(k * boxPixelsX +boxPixelsX *5 , resolutionY - boxPixelsY * arr[k] -boxPixelsX *5);
               	     		rect.setFillColor(sf::Color::Magenta);
               	     		window.draw(rect);
                    
                    
                    
                    }
                    
                    
                    else if(k!=elements-2){
                    
                    
               			if(k!=j+1&&k!=j+2){
     	 	 		sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[k]));
               	     		rect.setPosition(k * boxPixelsX +boxPixelsX *5 , resolutionY - boxPixelsY * arr[k] -boxPixelsX *5);
               	     		rect.setFillColor(sf::Color::Yellow);
               	     		window.draw(rect);
                    		}
                    }else{
                    
                    
             		       sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[k]));
               	     		rect.setPosition(k * boxPixelsX +boxPixelsX *5 , resolutionY - boxPixelsY * arr[k] -boxPixelsX *5);
               	     		rect.setFillColor(sf::Color::Yellow);
               	     		window.draw(rect);
                    
                    
                    
                    }
               
                }

                window.display();
		
               
                sf::sleep(sf::milliseconds(70));
                
            }
        }
    }
}

int separator(int arr[], int start, int end, int*& sarr) {
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        
        window.clear();

        for (int k = 0; k < elements; k++) {
            if (k == end || k == j) {
                sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[k]));
                rect.setPosition(k * boxPixelsX + boxPixelsX * 5, resolutionY - boxPixelsY * arr[k] - boxPixelsX * 5);
                rect.setFillColor(sf::Color::Red);
                window.draw(rect);
            } else {
                sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[k]));
                rect.setPosition(k * boxPixelsX + boxPixelsX * 5, resolutionY - boxPixelsY * arr[k] - boxPixelsX * 5);
                rect.setFillColor(sf::Color::Yellow);
                window.draw(rect);
            }
        }

        for (int k = 0; k < elements; k++) {
            if (arr[k] == sarr[k]) {
                sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[k]));
                rect.setPosition(k * boxPixelsX + boxPixelsX * 5, resolutionY - boxPixelsY * arr[k] - boxPixelsX * 5);
                rect.setFillColor(sf::Color::Magenta);
                window.draw(rect);
            }
        }

        window.draw(backgroundSprite);
        drawButtons(newArrayText, bubbleSortText, quickSortText, mergeSortText, heapSortText);
        window.display();
        sf::sleep(sf::milliseconds(70));

        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]);
    
    
    return i + 1;

}

void quickSort(int*& arr, int start, int end, int*& sarr) {

    if (start < end) {
        int pi = separator(arr, start, end, sarr);
        quickSort(arr, start, pi - 1, sarr);
        quickSort(arr, pi + 1, end, sarr);

    }

}



void merge(int arr[], int left, int mid, int right, int sortedArray[]) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        
        window.clear();

        for (int m = left; m <= right; m++) {
        
            if (m == left + i || m == mid + 1 + j) {
        
                sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[m]));
                rect.setPosition(m * boxPixelsX + boxPixelsX * 5, resolutionY - boxPixelsY * arr[m] - boxPixelsX * 5);
                rect.setFillColor(sf::Color::Red);
                window.draw(rect);
        
            } else if (arr[m] == sortedArray[m]) {
        
                sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[m]));
                rect.setPosition(m * boxPixelsX + boxPixelsX * 5, resolutionY - boxPixelsY * arr[m] - boxPixelsX * 5);
                rect.setFillColor(sf::Color::Magenta);
                window.draw(rect);
        
            } else {
        
                sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[m]));
                rect.setPosition(m * boxPixelsX + boxPixelsX * 5, resolutionY - boxPixelsY * arr[m] - boxPixelsX * 5);
                rect.setFillColor(sf::Color::Yellow);
                window.draw(rect);
        
            }
        
        }

        window.draw(backgroundSprite);
        drawButtons(newArrayText, bubbleSortText, quickSortText, mergeSortText, heapSortText);
        window.display();
        sf::sleep(sf::milliseconds(70));

        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;

}

void mergeSort(int arr[], int left, int right, int sortedArray[]) {

    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, sortedArray);
        mergeSort(arr, mid + 1, right, sortedArray);

        merge(arr, left, mid, right, sortedArray);

    }

}



void heapify(int arr[], int n, int i, int sortedArray[]) {
    int largest = i;  
    int l = 2 * i + 1;  
    int r = 2 * i + 2;  

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        
      //  window.clear();
        for (int k = 0; k < n; k++) {
            if (k == i || k == largest) {
     
                sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[k]));
                rect.setPosition(k * boxPixelsX + boxPixelsX * 5, resolutionY - boxPixelsY * arr[k] - boxPixelsX * 5);
                rect.setFillColor(sf::Color::Red);
                window.draw(rect);
     
            } else if (arr[k] == sortedArray[k]) {
     
                sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[k]));
                rect.setPosition(k * boxPixelsX + boxPixelsX * 5, resolutionY - boxPixelsY * arr[k] - boxPixelsX * 5);
                rect.setFillColor(sf::Color::Magenta);
                window.draw(rect);
     
            } else {
     
                sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[k]));
                rect.setPosition(k * boxPixelsX + boxPixelsX * 5, resolutionY - boxPixelsY * arr[k] - boxPixelsX * 5);
                rect.setFillColor(sf::Color::Yellow);
                window.draw(rect);
     
            }
     
        }
        
        
     for(int k=0;k<elements;k++)
        if (arr[k] == sortedArray[k]) {
            
                sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[k]));
                rect.setPosition(k * boxPixelsX + boxPixelsX * 5, resolutionY - boxPixelsY * arr[k] - boxPixelsX * 5);
                rect.setFillColor(sf::Color::Magenta);
                window.draw(rect);
            
            }

       // window.draw(backgroundSprite);
        drawButtons(newArrayText, bubbleSortText, quickSortText, mergeSortText, heapSortText);
        window.display();
        sf::sleep(sf::milliseconds(70));

        heapify(arr, n, largest, sortedArray); 

        
        window.clear();

        for (int k = 0; k < n; k++) {
            if (arr[k] == sortedArray[k]) {

                sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[k]));
                rect.setPosition(k * boxPixelsX + boxPixelsX * 5, resolutionY - boxPixelsY * arr[k] - boxPixelsX * 5);
                rect.setFillColor(sf::Color::Magenta);
                window.draw(rect);

            } else {

                sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[k]));
                rect.setPosition(k * boxPixelsX + boxPixelsX * 5, resolutionY - boxPixelsY * arr[k] - boxPixelsX * 5);
                rect.setFillColor(sf::Color::Yellow);
                window.draw(rect);

            }

        }
        
     for(int k=0;k<elements;k++)
        if (arr[k] == sortedArray[k]) {

                sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[k]));
                rect.setPosition(k * boxPixelsX + boxPixelsX * 5, resolutionY - boxPixelsY * arr[k] - boxPixelsX * 5);
                rect.setFillColor(sf::Color::Magenta);
                window.draw(rect);

            }


       // window.draw(backgroundSprite);
        drawButtons(newArrayText, bubbleSortText, quickSortText, mergeSortText, heapSortText);
        window.display();
        sf::sleep(sf::milliseconds(70));


    }



}

void heapSort(int arr[], int n, int sortedArray[]) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, sortedArray);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);



        window.clear();

        for (int k = 0; k < n; k++) {

            if (k == 0 || k == i) {

                sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[k]));
                rect.setPosition(k * boxPixelsX + boxPixelsX * 5, resolutionY - boxPixelsY * arr[k] - boxPixelsX * 5);
                rect.setFillColor(sf::Color::Red);
                window.draw(rect);

            } else if (arr[k] == sortedArray[k]) {

                sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[k]));
                rect.setPosition(k * boxPixelsX + boxPixelsX * 5, resolutionY - boxPixelsY * arr[k] - boxPixelsX * 5);
                rect.setFillColor(sf::Color::Magenta);
                window.draw(rect);
              
            } else {

                sf::RectangleShape rect(sf::Vector2f(boxPixelsX - 2, boxPixelsY * arr[k]));
                rect.setPosition(k * boxPixelsX + boxPixelsX * 5, resolutionY - boxPixelsY * arr[k] - boxPixelsX * 5);
                rect.setFillColor(sf::Color::Yellow);
                window.draw(rect);
            }


        }

      //  window.draw(backgroundSprite);

        drawButtons(newArrayText, bubbleSortText, quickSortText, mergeSortText, heapSortText);
        window.display();

       
     //   sf::sleep(sf::milliseconds(20));
        
        heapify(arr, i, 0, sortedArray);


    }





}




void handleButtonClick(int*& arr,int*&sortedArray) {

           if (clicks==1) {
                
                window.draw(newArrayButton2);
                sf::sleep(sf::milliseconds(50));
                window.draw(newArrayText);
                generateRandomArray(arr,sortedArray);
            }
           else if (clicks==2) {
                window.draw(bubbleSortButton2);
                bubbleSort(arr,sortedArray);
            }
            else if (clicks==3) {
                
                window.draw(newArrayButton2);
                sf::sleep(sf::milliseconds(50));
                window.draw(newArrayText);
                generateRandomArray(arr,sortedArray);
            }
            else if (clicks==4) {
                window.draw(quickSortButton2);
                quickSort(arr,0,elements-1,sortedArray);
            }
            else if (clicks==5) {
                
                window.draw(newArrayButton2);
                sf::sleep(sf::milliseconds(50));
                window.draw(newArrayText);
                generateRandomArray(arr,sortedArray);
            }
            
            else if (clicks==6) {
                window.draw(quickSortButton2);
                quickSort(arr,0,elements-1,sortedArray);
            }
            
            else if (clicks==7) {
                
                window.draw(newArrayButton2);
                sf::sleep(sf::milliseconds(50));
                window.draw(newArrayText);
                generateRandomArray(arr,sortedArray);
            }
        	
	    else if (clicks==8) {
            
                window.draw(quickSortButton2);
                heapSort(arr,elements,sortedArray);
            
            }
    
}
