#pragma once
#include <iostream>

template<typename T>
class BinaryTreeNode {
public:
	T data;
    BinaryTreeNode<T>* parent;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

	BinaryTreeNode(T data) {
		this->data = data;
        parent = 0;
		left = 0;
		right = 0;
	}
};	

template<typename T>
class BinaryTree {
public:
	BinaryTreeNode<T>* root;
	BinaryTree() {
		root = 0;
	}

	void insert(T data) {
        BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(data);

        if (root == 0) {
            root = newNode;
        }
        else {
            BinaryTreeNode<T>* temp = root;
            BinaryTreeNode<T>* parent = 0;

            while (temp != 0) {
                parent = temp;

                if (data < temp->data) {
                    temp = temp->left;
                }
                else {
                    temp = temp->right;
                }
            }

            if (data < parent->data) {
                parent->left = newNode;
            }
            else {
                parent->right = newNode;
            }

            newNode->parent = parent;
        }
    }



    class Iterator {
    private:
        BinaryTreeNode<T>* root;
        BinaryTreeNode<T>* curr;

        void pushLeftNodes(BinaryTreeNode<T>* node) {
            while (node != 0) {
                curr = node;
                node = node->left;
            }
        }

    public:
        Iterator(BinaryTreeNode<T>* root) : root(root), curr(0) {
            pushLeftNodes(root);
        }

        T operator*() {
            if (curr == 0) {
                throw std::runtime_error("Iterator out of range");
            }
            return curr->data;
        }

        Iterator& operator++() {
            if (curr == 0) {
                return *this;
            }
            if (curr->right != 0) {
                pushLeftNodes(curr->right);
            }
            else {
                BinaryTreeNode<T>* parent = curr->parent;
                while (parent != 0 && curr == parent->right) {
                    curr = parent;
                    parent = parent->parent;
                }
                curr = parent;
            }
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return curr != other.curr;
        }

    };



    Iterator begin() {
        return Iterator(root);
    }

    Iterator end() {
        return Iterator(0);
    }
};