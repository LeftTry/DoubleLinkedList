#include <iostream>
#include "DoubleLinkedList.h"
#include "ctime"
#include "vector"

using namespace std;

DoubleLinkedList<int> dll;

int makeField(){
    srand((unsigned) time(0));
    int size = rand();
    size %= 1001;
    cout << "Size: " << size << endl;
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

void ballsCheck(int& startpos, vector<Node<int>*>& nB, int& q){
    if(nB[0]->get_el() == nB[1]->get_el() && nB[1]->get_el() == nB[2]->get_el()) {
        nB[0]->get_prev()->set_next(nB[2]->get_next());
        nB[2]->get_next()->set_prev(nB[0]->get_prev());
        q++;
    }
    else if(nB[1]->get_el() == nB[2]->get_el() && nB[2]->get_el() == nB[3]->get_el()){
        nB[1]->get_prev()->set_next(nB[3]->get_next());
        nB[3]->get_next()->set_prev(nB[1]->get_prev());
        q++;
    }
    else if(nB[2]->get_el() == nB[3]->get_el() && nB[3]->get_el() == nB[4]->get_el()){
        nB[2]->get_prev()->set_next(nB[4]->get_next());
        nB[4]->get_next()->set_prev(nB[2]->get_prev());
        q++;
    }
    nB.clear();
}

void generateBall(int size, int& startpos, Node<int>*startnode, vector<Node<int>*>& nearBalls, int& q){
    srand((unsigned) time(0));
    int color = rand() % 5;
    cout << "color: " << color << endl;
    cout << "Position now is: " << startpos << endl;
    int pos = -1;
    cin >> pos;
    while(pos > startpos + 5 || pos < startpos - 5 || pos > size || pos < 0) {
        cout << "Incorrect position. Please try again" << endl;
        cout << "Position now is: " << startpos << endl;
        cin >> pos;
    }
    dll.addAfterEl(startnode, pos - startpos - 1, color);
    Node<int>* node = dll.get_head();
    int o = 0;
    cout << startpos << endl;
    while(node->get_next() != nullptr){
        if(o >= startpos - 29 && o <= startpos + 30) {
            if(o == startpos){
                nearBalls[2] = node;
                nearBalls[1] = node->get_prev();
                nearBalls[3] = node->get_next();
                nearBalls[4] = node->get_next()->get_next();
                nearBalls[0] = node->get_prev()->get_prev();
            }
        }
        o++;
        if(o > startpos + 30) break;
        node = node->get_next();
    }
    o = 0;
    node = dll.get_head();
    ballsCheck(startpos, nearBalls, q);
    while(node->get_next() != nullptr){
        if(o >= startpos - 29 && o <= startpos + 30) {
            cout << node->get_el() << " ";
        }
        o++;
        if(o > startpos + 30) break;
        node = node->get_next();
    }
    for(int i = 0;i < 58 - 2 * (startpos - pos);i++) cout << " ";
    cout << "^" << endl;
    startpos = pos + 1;
}

void generateRandBall(int size, int& startpos, Node<int>*startnode, vector<Node<int>*>& nearBalls, int& q){
    srand((unsigned) time(0));
    int color = rand() % 5;
    int pos = -1;
    pos = startpos + rand() % 11 - 5;
    while(pos > startpos + 5 || pos < startpos - 5) {
        pos = startpos + rand() % 11 - 5;
        if(pos > size || pos < 0) pos = size / 2;
    }
    dll.addAfterEl(startnode, pos - startpos, color);
    Node<int>* node = dll.get_head();
    int o = 0;
    while(node->get_next() != nullptr){
        if(o >= startpos - 29 && o <= startpos + 30) {
            if(o == startpos){
                nearBalls[2] = node;
                nearBalls[1] = node->get_prev();
                nearBalls[3] = node->get_next();
                nearBalls[4] = node->get_next()->get_next();
                nearBalls[0] = node->get_prev()->get_prev();
            }
        }
        o++;
        if(o > startpos + 30) break;
        node = node->get_next();
    }
    ballsCheck(startpos, nearBalls, q);
    startpos = pos + 1;
}

void findAllBalls(int& q){
    Node<int>  node = *dll.get_head();
    while(node.get_next() != nullptr){
        if(node.get_el() == node.get_next()->get_el() && node.get_next()->get_next()->get_el() == node.get_el()){
            node.get_prev()->set_next(node.get_next()->get_next()->get_next());
            node.get_next()->get_next()->get_next()->set_prev(node.get_prev());
            node = *node.get_next()->get_next()->get_next();
            q++;
        }
        else{
            node = *node.get_next();
        }
    }
}

int main() {
    bool f = false;
    while(!f){
        int size = makeField();
        bool finished = false;
        int startpos = size / 2;
        int q = 0;
        vector<Node<int> *> nearBalls(5);
        bool bot = false;
        cout << "Do you want to activate bot?(y/n)" << endl;
        char a;
        cin >> a;
        Node<int> *startnode = dll.get_head();
        int o = 0;
        while (startnode->get_next() != nullptr) {
            if (o == startpos) break;
            o++;
            startnode = startnode->get_next();
        }
        //findAllBalls(q);
        if (a == 'n')
            while (!finished) {
                generateBall(size, startpos, startnode, nearBalls, q);
                if (q >= 200) finished = true;
                cout << "Your score is: " << q << endl;
            }
        else if (a == 'y') {
            int i = 0;
            while (!finished) {
                //cout << "ok";
                generateRandBall(size, startpos, startnode, nearBalls, q);
                if (q >= 1000) finished = true;
                i++;
                if (i == 1e2) {
                    Node<int> node = *dll.get_head();
                    int o = 0;
                    while (node.get_next() != nullptr) {
                        if (o >= startpos - 29 && o <= startpos + 30) {
                            cout << node.get_el() << " ";
                        }
                        o++;
                        if (o > startpos + 30) break;
                        node = *node.get_next();
                    }
                }
                i = 0;
            }
        }
        cout << "You finished with score: " << q << endl;
        cout << "Do you want to restart?(y/n)" << endl;
        cin >> a;
        if (a == 'n') f = true;
}
    return 0;
}
