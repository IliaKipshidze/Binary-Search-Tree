#include <iostream>
#include "BST.cpp"
using namespace std;
int main() {
	BST<int> B; //შევქმნათ int-ების BST
	B.show(cout); //უნდა გვითხრას, რომ BST ცარიელია
	//ჩავამატოთ ელემენტები
	B.Insert(3);
	B.Insert(19);
	B.Insert(0);
	B.Insert(32);
	B.Insert(32); //ვცადოთ იგივე ელემენტის კიდევ ჩამატება (უნდა დაგვიწეროს რომ ასეთი ელემენტი BST-ში უკვე არის)
	B.Insert(40);
	B.Insert(2);
	B.Insert(-11);
	B.Insert(37);
	//შევემოწმოთ რამდენად სწორად მუშაობს search() ფუნქცია
	cout << "3 in BST? " << boolalpha << B.search(3) << endl; //true
	cout << "-11 in BST? " << boolalpha << B.search(-11) << endl; //true
	cout << "7 in BST? " << boolalpha << B.search(7) << endl; //false
	cout << "40 in BST? " << boolalpha << B.search(40) << endl; //true
	cout << "32 in BST? " << boolalpha << B.search(32) << endl; //true
	cout << "12 in BST? " << boolalpha << B.search(12) << endl; //false
	cout << "19 in BST? " << boolalpha << B.search(19) << endl; //true
	cout << "2 in BST? " << boolalpha << B.search(2) << endl; //true
	cout << "-16 in BST? " << boolalpha << B.search(-16) << endl; //false
	cout << "0 in BST? " << boolalpha << B.search(0) << endl; //true
	cout << "37 in BST? " << boolalpha << B.search(37) << endl; //true
	cout << "BST is empty: " << boolalpha << B.empty() << endl; //false
	cout << "preorder:" << endl; //შევამოწმოთ, ხომ სწორად მუშაობს Preorder() ფუნქცია
	B.Preorder(cout);
	cout << "show BST:" << endl;//შევამოწმოთ, show() ფუნქცია, ის უნდა დაემთხვეს Preorder()-ს
	B.show(cout);
	cout << "inorder:" << endl; //შევამოწმოთ, ხომ სწორად მუშაობს Inorder() ფუნქცია
	B.Inorder(cout);
	cout << "postorder:" << endl; //შევამოწმოთ, ხომ სწორად მუშაობს Postorder() ფუნქცია
	B.Postorder(cout);
	cout << "37 in BST? " << boolalpha << B.search(37) << endl; //true
	//ახლა ამოვშალოთ 37
	B.remove(37);
	cout << "37 in BST? " << boolalpha << B.search(37) << endl; //false
	cout << "preorder:" << endl;
	B.Preorder(cout);
	//ვცადოთ კიდევ თავიდან ამოშლა, უნდა გვითხრას, რომ ასეთი ელემენტი არ არის
	B.remove(37);
	//წავშალოთ ყველა ელემენტი 
	while (!B.empty()) {
		B.remove(B.getRoot());
	}
	cout << "BST is empty: " << boolalpha << B.empty() << endl; //true
	B.show(cout); //ვცადოთ დაბეჭდვა, არ უნდა დაგვიბეჭდოს, რადგან ცარიელია
	int b = B.getRoot(); //უნდა გვითხრას რომ სტრუქტურა ცარიელია და ბრუნდება ნაგავი
	//ახლა ვაჩვენოთ, რომ ვინაიდან ტემპლეიტ კლასი გვაქვს, int-ის გარდა სხვა ტიპის BST-ების შექმნაც შეგვიძლია
	BST<char> A;
	A.Insert('B');
	A.Insert('Y');
	A.Insert('C');
	A.Insert('A');
	A.Insert('N');
	A.Insert('M');
	A.show(cout);
	cout << "inorder:" << endl; 
	A.Inorder(cout);
	cout << "postorder:" << endl; 
	A.Postorder(cout);
	cout << "'C' in BST? " << boolalpha << A.search('C') << endl; //true
	A.remove('C');
	cout << "'C' in BST? " << boolalpha << A.search('C') << endl; //false 
	A.show(cout);
	/*	                                                     პროგრამის აღწერა
		BST არის ორობითი ძებნის ხის template კლასი, რომელსაც გააჩნია ყველა მოთხოვნილი და საჭირო ფუნქციები, სამნაირი ბეჭდვის, ჩამატების
	წაშლის, ძებნის და ა.შ. უმეტესობა მათგანი არის რეკურსიული, რის გამოც ზოგიერთ შემთხვევაში დაგვჭირდა დამხმარე ფუნქციები, რომ მომხმარებელს 
	დისკომფორტი არ შეექმნას და პირდაპირ გამოიძახოს მისთვის სასურველი ფუნქცია. დამხმარე ფუნქციები არის კლასის private წევრები რადგან მომხმარებელს
	მასზე წვდომა არასოდეს არ უნდა დასჭირდეს. main()-ში ვტესტავთ ყველა ფუნქციას int-ების BST-სთვის. ბოლოს კი ვაჩვენებთ, template კლასის უპირატესობას
	იმით, რომ ჩვენ შევძელით არა მხოლოდ int-ების BST-ს შექმნა, არამედ ჩარებისაც, და ვაჩვენეთ, რომ მასზეც უპრობლემოდ იმუშავებენ ჩვენი ფუნქციები.
	
	*/
}