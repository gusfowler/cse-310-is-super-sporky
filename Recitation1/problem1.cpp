void main(Node* H, Node* X, Node* Y) {
    Node* current = H;

    while (current != nullptr) {
        if (current == X){
            Node* temp = current->next;
            X->next = Y;
            Y->next = temp;
            break;
        }
        current = current->next;
    }
}