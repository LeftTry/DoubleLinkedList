#include <iostream>
#include "DoubleLinkedList.h"
#include "ctime"
#include "vector"

using namespace std;

DoubleLinkedList<int> dll;

int makeField(){
    srand((unsigned) time(0));
    int size = rand();
    if(size >= 1000) size /= 10;
    cout << size << endl;
    int randval = rand();
    dll.addToBegin(randval % 5);
    for (int i = 0; i < size - 1; ++i) {
        randval = rand();
        dll.addToEnd(randval % 5);
    }
    Node<int> node = *dll.get_head();
    int o = 0;
    while(node.get_next() != nullptr){
        if(o >= size/2 - 29 && o <= size/2 + 30) cout << node.get_el() << " ";
        o++;
        node = *node.get_next();
    }
    for(int i = 0;i < 58;i++) cout << " ";
    cout << "^" << endl;
    return size;
}

void generateBall(int& startpos, vector<Node<int>>& nearBalls){
    srand((unsigned) time(0));
    int color = rand() % 5;
    cout << color << endl;
    cout << "Position now is: " << startpos << endl;
    int pos = -1;
    cin >> pos;
    while(pos > startpos + 5 || pos < startpos - 5) {
        cout << "Incorrect position. Please try again" << endl;
        cout << "Position now is: " << startpos << endl;
        cin >> pos;
    }
    dll.addToIndex(color, pos - 1);
    //cout << dll << endl;
    Node<int> node = *dll.get_head();
    int o = 0;
    while(node.get_next() != nullptr){
        if(o >= startpos - 29 && o <= startpos + 30) {
            cout << node.get_el() << " ";
            if(o == startpos){
                nearBalls[2] = node;
                nearBalls[1] = *node.get_prev();
                nearBalls[3] = *node.get_next();
                nearBalls[4] = *node.get_next()->get_next();
                nearBalls[0] = *node.get_prev()->get_prev();
            }
        }
        o++;
        if(o > startpos + 30) break;
        node = *node.get_next();
    }
    for(int i = 0;i < 58 - 2 * (startpos - pos);i++) cout << " ";
    cout << "^" << endl;
    startpos = pos;
}

void generateRandBall(int& startpos, vector<Node<int>>& nearBalls){
    srand((unsigned) time(0));
    int color = rand() % 5;
    //cout << color << endl;
    //cout << "Position now is: " << startpos << endl;
    int pos = -1;
    //cin >> pos;
    pos = startpos + rand() % 11 - 5;
    //while(pos > startpos + 5 || pos < startpos - 5) {
        //cout << "Incorrect position. Please try again" << endl;
        //cout << "Position now is: " << startpos << endl;
        //cin >> pos;
    //}
    //cout << pos << endl;
    dll.addToIndex(color, pos - 1);
    //cout << "ok";
    //cout << dll << endl;
    Node<int> node = *dll.get_head();
    int o = 0;
    while(node.get_next() != nullptr){
        if(o >= startpos - 29 && o <= startpos + 30) {
            //cout << node.get_el() << " ";
            if(o == startpos){
                nearBalls[2] = node;
                nearBalls[1] = *node.get_prev();
                nearBalls[3] = *node.get_next();
                nearBalls[4] = *node.get_next()->get_next();
                nearBalls[0] = *node.get_prev()->get_prev();
            }
        }
        o++;
        if(o > startpos + 30) break;
        node = *node.get_next();
    }
    //for(int i = 0;i < 58 - 2 * (startpos - pos);i++) cout << " ";
    //cout << "^" << endl;
    startpos = pos;
}

void ballsCheck(int& startpos, vector<Node<int>>& nB, int& q){
    if(nB[0].get_el() == nB[1].get_el() && nB[1].get_el() == nB[2].get_el()) {
        dll.deleteFromIndex(startpos - 2);
        dll.deleteFromIndex(startpos - 1);
        dll.deleteFromIndex(startpos);
        q++;
    }
    else if(nB[1].get_el() == nB[2].get_el() && nB[2].get_el() == nB[3].get_el()){
        dll.deleteFromIndex(startpos + 1);
        dll.deleteFromIndex(startpos - 1);
        dll.deleteFromIndex(startpos);
        q++;
    }
    else if(nB[2].get_el() == nB[3].get_el() && nB[3].get_el() == nB[4].get_el()){
        dll.deleteFromIndex(startpos + 2);
        dll.deleteFromIndex(startpos + 1);
        dll.deleteFromIndex(startpos);
        q++;
    }
}

int main() {
    int size = makeField();
    bool finished = false;
    int startpos = size / 2;
    int q = 0;
    vector<Node<int>> nearBalls(5);
    bool bot = false;
    cout << "Do you want to activate bot?(y/n)" << endl;
    char a;
    cin >> a;
    if(a == 'n')
        while(!finished){
            generateBall(startpos, nearBalls);
            ballsCheck(startpos, nearBalls, q);
            if(q == 10) finished = true;
        }
    else if(a == 'y') {
        int i = 0;
        while (!finished) {
            generateRandBall(startpos, nearBalls);
            ballsCheck(startpos, nearBalls, q);
            if (q == 10000) finished = true;
            i++;
            if(i == 1e6){
                Node<int> node = *dll.get_head();
                int o = 0;
                while(node.get_next() != nullptr){
                    if(o >= startpos - 29 && o <= startpos + 30) {
                        cout << node.get_el() << " ";
                    }
                    o++;
                    if(o > startpos + 30) break;
                    node = *node.get_next();
                }
            }
        }
    }
    return 0;
}
