#pragma once
template <typename T> //გვაქვს ტემპლეიტ კლასი
class TreeNode {
	template <typename T> //ვინაიდან friend გვიწერია, გვიწევს template-ს კიდევ გამეორება
	friend class BST;
	T item; //T ტიპის მონაცემი რომელიც შეინახება კვანძში
	TreeNode<T>* Lchild; //კვანძის მარცხენა შვილი
	TreeNode<T>* Rchild; //კვანძის მარჯვენა შვილი
	TreeNode<T>* Parent; //კვანძის მშობელი
public:
	TreeNode<T>() { //უპარამეტრო კონსტრუქტორი
		Lchild = Rchild = nullptr;
	}
	//პარამეტრებიანი კონსტრუქტორით ინიციალიზება
	TreeNode<T>(T i, TreeNode<T>* P = nullptr, TreeNode<T>* L = nullptr, TreeNode<T>* R = nullptr) {
		item = i;
		Lchild = L;
		Rchild = R;
		Parent = P;
	}
	//აბრუნებს კვანძში ჩაწერილ მნიშვნელობას
	T getItem()const {
		return item;
	}
};