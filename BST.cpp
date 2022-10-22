#include <iostream>
using namespace std;
#include "TreeNode.h"
template <typename T>
class BST {
	TreeNode<T>* myRoot;
	void insertHelper(T el, TreeNode<T>* node) {
		if (node->item > el) { //თუ ნაკლებია ნოუდის მნიშვნელობაზე
			if (node->Lchild == nullptr) { //და ამავე დროს მარცხენა შვილი აღარ ყავს
				//მაშინ შევქმნათ და დავამატოთ ახალი კვანძი
				TreeNode<T>* ptr = new TreeNode<T>(el, node); //მშობლად გადაეცემა node
				node->Lchild = ptr; //node-ს მარცხენა შვილი გახდეს შექმნილი ახალი (ჩამატებული) კვანძი
			}
			else insertHelper(el, node->Lchild); //თუარადა (ანუ თუ მარცხენა შვილი ყავს) მაშინ რეკურსიულად გადავიდეთ მარცხენა ქვეხეზე (ან მარცხენა შვილზე)
		}
		else if (node->item < el) { //თუ მეტია ნოუდის მნიშვნელობაზე
			if (node->Rchild == nullptr) { //და ამავე დროს მარჯვენა შვილი აღარ ყავს
				//მაშინ შევქმნათ და დავამატოთ ახალი კვანძი
				TreeNode<T>* ptr = new TreeNode<T>(el, node); //მშობლად გადაეცემა node
				node->Rchild = ptr; //node-ს მარჯვენა შვილი გახდეს შექმნილი ახალი (ჩამატებული) კვანძი
			}
			else insertHelper(el, node->Rchild); //თუარადა (ანუ თუ მარჯვენა შვილი ყავს) მაშინ რეკურსიულად გადავიდეთ მარჯვენა ქვეხეზე (ან მარჯვენა შვილზე)
		}
	}
	void searchHelper(T el, TreeNode<T>* node, bool& found) {
		if (node == nullptr) return; //თუ null-ს მივადექით, დავბრუნდეთ უკან
		else if (node->item == el) { found = true; return; } //თუ ვიპოვნეთ, found გახდეს true, და გამოვიდეთ
		else {
			//თუ ჯერჯერობით ნაპოვნი არ არის გავაგრძელოთ ძებნა მარცხენა და მარჯვენა ქვეხეებში
			searchHelper(el, node->Lchild, found); 
			searchHelper(el, node->Rchild, found);
		}
	}
	//ეს სამი ფუნქცია უმარტივესია
	void InorderHelper(TreeNode<T>* node, ostream& out) {
		if (node != nullptr) {
			InorderHelper(node->Lchild, out);
			out << node->item << "  ";
			InorderHelper(node->Rchild, out);
		}
	}
	void PreorderHelper(TreeNode<T>* node, ostream& out) {
		if (node != nullptr) {
			out << node->item << "  ";
			PreorderHelper(node->Lchild, out);
			PreorderHelper(node->Rchild, out);
		}
	}
	void PostorderHelper(TreeNode<T>* node, ostream& out) {
		if (node != nullptr) {
			PostorderHelper(node->Lchild, out);
			PostorderHelper(node->Rchild, out);
			out << node->item << "  ";
		}
	}
	void removeHelper(T el, TreeNode<T>* node) {
		if (node->item == el) { //თუ ამოსაღები ელემენტი ამ კვანძზეა (node-ზე)
			TreeNode<T>* tmp; //შემოგვაქვს დამხმარე პოინტერის ტიპის ცვლადი
			if (node->Lchild == nullptr && node->Rchild == nullptr) { //თუ node-ს არცერთი შვილი არ ყავს
				if (node == myRoot) { //თუ node -ს არცერთი შვილი არ ყავს და თან ხის ფესვია (ანუ მხოლოდ ის არის BST-ში)
					//მაშინ უბრალოდ მას წავშლით და მორჩა.
					delete node;
					myRoot = nullptr;
					return;
				}
				if (node->Parent->Rchild == node) { //თუ node არის მისი მშობლის მარჯვენა შვილი, მისი მშობლის Rchild ახლა მიუთითებს nullptr-ზე
					node->Parent->Rchild = nullptr; 
				}
				else node->Parent->Lchild = nullptr; //თუ მარცხენა შვილია ასევე, მისი მშობლის Lchild ახლა მიუთითებს nullptr-ზე
				delete node; //წავშალოთ კვანძი
			}
			else if (node->Lchild != nullptr) { //თუ ყავს მარცხენა შვილი
				tmp = node->Lchild; //გადავიდეთ მისი მარცხენა ქვეხის ფესვზე (ანუ node-ს მარცხენა შვილზე)
				while (tmp->Rchild != nullptr) {
					tmp = tmp->Rchild; //ვიპოვოთ მარცხენა ქვეხის უმარჯვენესი ელემენტი
				}
				node->item = tmp->item; //და ამ უმარჯვენესის მნიშვნელობა გადავიტანოთ node-ში
				//თავად უმარჯვენესი კი წავშალოთ
				if (tmp->Parent->Rchild == tmp) {
					tmp->Parent->Rchild = nullptr; 
				}
				else tmp->Parent->Lchild = nullptr;
				delete tmp;
			}
			else { //ეს ის შემთხვევაა როცა node-ს ყავს მარჯვენა შვილი
				//ყველაფერი ანალოგიურია
				tmp = node->Rchild; //გადავიდეთ მისი მარჯვენა ქვეხის ფესვზე (ანუ node-ს მარჯვენა შვილზე)
				while (tmp->Lchild != nullptr) {
					tmp = tmp->Lchild; //ვიპოვოთ მარჯვენა ქვეხის უმარცხენესი ელემენტი
				}
				node->item = tmp->item; //და ამ უმარცხენესის მნიშვნელობა გადავიტანოთ node-ში
				//თავად უმარცხენესი კი წავშალოთ
				if (tmp->Parent->Rchild == tmp) {
					tmp->Parent->Rchild = nullptr;
				}
				else tmp->Parent->Lchild = nullptr;
				delete tmp;
			}
		}
		else if (node->item < el)removeHelper(el, node->Rchild); //თუ მასზე მეტია, ანუ მარჯვენა ქვეხეში უნდა იყოს და რეკურსიულად გადავალთ მარჯვენა შვილზე
		else removeHelper(el, node->Lchild); //სხვა შემთხვევაში (ანუ როცა მასზე ნაკლებია და მარცხენა ქვეხეში უნდა იყოს), გადავალთ მარცხენა შვილზე
	}
public:
	BST<T>() { myRoot = nullptr; }
	
	bool search(T el) {
		bool found = false; 
		searchHelper(el, myRoot, found); //გამოვიძახებთ დამხმარე ფუნქციას შესაბამისი პარამეტრებით, და თუ იგი el ელემენტს იპოვნის found გახდება true
		return found; 
	}
	void Insert(T el) {
		if (!search(el)) { //თუ გადაცემული ელემენტი სტრუქტურაში არ არის 
			if (myRoot != nullptr)insertHelper(el, myRoot); //თუ მასში ერთი ელემენტი მაინც არის, გამოიძახება დამხმარე ფუნქცია, შესაბამისი პარამეტრებით
			else { //თუ ერთი ელემენტიც არ არის, მაშინ მხოლოდ ამ ორი ხაზით ჩავამატებთ ახალ ელემენტს, რომელიც გახდება ხის ფესვი
				TreeNode<T>* ptr = new TreeNode<T>(el);
				myRoot = ptr;
			}
		}
		else cout << el << " already exists in BST" << endl;
	}
	void Inorder(ostream &out) { //თუ სტრუქტურა ცარიელია, არაფერსაც არ დაგვიბეჭდავს
		if (myRoot == nullptr) {
			cout << "BST is empty!"<<endl; return;
		}
		InorderHelper(myRoot, out); // თუ ცარიელი არ არის მაშინ გამოიძახებს დამხმარე ფუნქციას, შესაბამისად გადაცემული პარამეტრებით
		cout << endl;               //და მონაცემები დაიბეჭდება inorder წესით
	}
	void Preorder(ostream& out) { //თუ სტრუქტურა ცარიელია, არაფერსაც არ დაგვიბეჭდავს
		if (myRoot == nullptr) {
			cout << "BST is empty!"<<endl; return;
		}
		PreorderHelper(myRoot, out); //თუ ცარიელი არ არის მაშინ გამოიძახებს დამხმარე ფუნქციას, შესაბამისად გადაცემული პარამეტრებით
		cout << endl;                //და მონაცემები დაიბეჭდება preorder წესით
	}
	void Postorder(ostream& out) {
		if (myRoot == nullptr) { //თუ სტრუქტურა ცარიელია, არაფერსაც არ დაგვიბეჭდავს
			cout << "BST is empty!" << endl; return;
		}
		PostorderHelper(myRoot, out); //თუ ცარიელი არ არის მაშინ გამოიძახებს დამხმარე ფუნქციას, შესაბამისად გადაცემული პარამეტრებით
		cout << endl;                 //და მონაცემები დაიბეჭდება postorder წესით
	}
	void remove(T el) {
		if (search(el)) { //თუ ეს ელემენტი, რომლის ამოშლაც გვინდა მართლაც არის BST-ში
			removeHelper(el, myRoot); //მაშინ გამოიძახებს შესაბამის დამხმარე ფუნქციას, რომელიც მას წაშლის
		}
		else cout << el << " is not in BST!"<< endl;
	}
	void show(ostream& out) { 
		if (!empty()) { //თუ სტრუქტურა ცარიელი არ არის მაშინ უბრალოდ გამოიძახებს Preorder() მონაცემების ბეჭდვის ფუნქციას
			Preorder(out);
		}
		else out << "BST is empty!" << endl; //თუ ცარიელია, გამოგვიტანს შესაბამის შეტყობინებას
	}
	bool empty() const {
		return myRoot == nullptr;
	}
	T getRoot()const { //ეს ფუნქცია დაგვიბრუნებს ხის ფესვის მონაცებს, თუ ის არსებობს, თუარადა დაგვიწერს, რომ BST-ცარიელია და ბრუნდება ნაგავი
		if (myRoot != nullptr) {
			return myRoot->item;
		}
		else {
			cout << "BST is empty! returning garbage" << endl;
			T* tmp = new T;
			return *tmp; //ბრუნდება ნაგავი
		}
	}
};