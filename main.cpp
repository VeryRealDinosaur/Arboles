#include <iostream>

// Definición de la estructura del nodo del árbol
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Función para insertar un nodo en el árbol
void insert(TreeNode*& root, int val) {
    if (!root) {
        root = new TreeNode(val);
        return;
    }
    if (val < root->data) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

// Función para mostrar el árbol por el Método de Búsqueda Binaria (inorden)
void inOrderTraversal(TreeNode* root) {
    if (!root) return;
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Función para buscar un número en el árbol
bool search(TreeNode* root, int val) {
    if (!root) return false;
    if (root->data == val) return true;
    if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

// Función para obtener la altura de un nodo
int getHeight(TreeNode* node) {
    if (!node) return 0;
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

// Función para obtener la altura de todo el árbol
int getTreeHeight(TreeNode* root) {
    return getHeight(root);
}

// Función para contar el número de nodos en el árbol
int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void preOrderTraversal(TreeNode* root) {
    if (!root) return;
    std::cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root) {
    if (!root) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
}

void printTree(TreeNode* root, int depth = 0) {
    if (!root) return;

    // Adjust spacing based on depth
    const int spaces = 4;
    for (int i = 0; i < depth * spaces; ++i) {
        std::cout << " ";
    }

    // Print the current node
    std::cout << root->data << std::endl;

    // Recursively print left and right subtrees
    printTree(root->left, depth + 1);
    printTree(root->right, depth + 1);
}

// Función para borrar un nodo
TreeNode* deleteNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* minRight = root->right;
        while (minRight->left) {
            minRight = minRight->left;
        }
        root->data = minRight->data;
        root->right = deleteNode(root->right, minRight->data);
    }
    return root;
}

void deleteTree(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    // Recursively delete left and right subtrees
    deleteTree(node->left);
    deleteTree(node->right);

    // Delete the current node
    delete node;
}

// Función principal
int main() {
    TreeNode *root = nullptr;
    int option;
    int dato;

    while (true) {
        std::cout << "Ingresa una opción: \n\n "
                     "1. Insertar un elemento\n" //DONE
                     "2. Mostrar árbol\n" //TODO
                     "3. Buscar elemento\n" //DONE
                     "4. Obtener altura del árbol\n" //DONE
                     "5. Total de nodos del árbol\n" //DONE
                     "6. Recorrido Pre-Orden\n" //DONE
                     "7. Recorrido In-Orden\n" //DONE
                     "8. Recorrido Post-Orden\n" //DONE
                     "9. Borrar un elemento\n" //DONE
                     "10. Borrar árbol\n" //DONE
                     "11. Salir\n"; //DONE
        std::cin >> option;

        switch (option) {
            case 1: { //DONE
                std::cout << "Ingrese un valor: ";
                std::cin >> dato;
                insert(root, dato);
                std::cin.clear();
                std::getchar();
                break;
            }
            case 2: { //TODO
                printTree(root);
            }
            case 3: { //DONE
                std::cout << "Ingrese un valor: ";
                std::cin >> dato;
                if (search(root, dato)) {
                    std::cout << "Número encontrado.\n";
                } else {
                    std::cout << "Número no encontrado.\n";
                }
                getchar();
                std::cin.clear();
                break;
            }
            case 4: { //DONE
                std::cout << "Altura del árbol: " << getTreeHeight(root) << std::endl;
                getchar();
                std::cin.clear();
                break;
            }
            case 5: { //DONE
                std::cout << "Número de nodos: " << countNodes(root) << std::endl;
                getchar();
                std::cin.clear();
                break;
            }
            case 6: { //Done
                std::cout << "Recorrido Pre-Orden: \n";
                preOrderTraversal(root);
                getchar();
                std::cin.clear();
                break;
            }
            case 7: { //DONE
                std::cout << "Recorrido In-Orden: \n";
                inOrderTraversal(root);
                getchar();
                std::cin.clear();
                break;
            }

            case 8: { //Done
                std::cout << "Recorrido Post-Orden: \n";
                postOrderTraversal(root);
                getchar();
                std::cin.clear();
                break;
            }

            case 9: {
                std::cout << "Inserte valor del nodo a eliminar: \n";
                int nodo;
                std::cin >> nodo;
                deleteNode(root, nodo);
                break;
            }

            case 10: {
                deleteTree(root);
            }

            case 11: {
                std::cout << "Saliendo del programa.\n";
                return 0;
            }

            default: { //DONE
                std::cout << "Opción inválida. Por favor, ingrese una opción válida.\n";
                getchar();
                std::cin.clear();
                break;
            }
        }
    }
}