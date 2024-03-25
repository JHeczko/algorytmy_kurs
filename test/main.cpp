
position Previous(position p){
    if(p == nullptr){
        position tmp = HEAD; //w domysle pierwszy elelemy listy
        while(tmp->next != nullptr){
            tmp = tmp->next;
        }
        return tmp;
    }
    else{
        return p->previous;
    }
}