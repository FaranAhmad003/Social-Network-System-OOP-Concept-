//#include<iostream>
//#include<fstream>
//#include<cstring>
//#include<string.h>
//using namespace std;
//class Helper;
//template<class T>
//class Deallocation;
//class Object;
//class Date;
//class Activity;
//class Comment;
//class Post;
//class Activity;
//class Facebook;
//
//
//class Helper
//{
//public:
//	static int StringLenght(const char* str)
//	{
//		int length = 0;
//		for (int i = 0; str[i] != '\0'; i++)
//		{
//			length++;
//		}
//		return length;
//
//	}
//	static void StringCopy(char*& dest, const char*& src)
//	{
//		int i = 0;
//		for (; src[i] != '\0'; i++)
//		{
//			dest[i] = src[i];
//		}
//		dest[i] = '\0';
//	}
//	static char* GetStringFromBuffer(const char* str)
//	{
//		int size = Helper::StringLenght(str);
//		char* temp = new char[size + 1];
//		Helper::StringCopy(temp, str);
//		return temp;
//	}
//
//	static int stringcompare(const char* str1, const char* str2)
//	{
//		int flag = 1, i = 0;
//		while (str1[i] != '\0' && str2[i] != '\0')
//		{
//			if (str1[i] != str2[i])
//			{
//				flag = 0;
//				break;
//			}
//			i++;
//		}
//		return flag;
//	}
//
//
//	bool stringcompare1(const char* str1, const char* str2)
//	{
//		bool flag = true, i = 0;
//		while (str1[i] != '\0' && str2[i] != '\0')
//		{
//			if (str1[i] != str2[i])
//			{
//				flag = false;
//				break;
//			}
//			i++;
//		}
//		return flag;
//	}
//};
//template<class T> //----------------------------------------------template-------------------------------
//class Deallocation
//{
//public:
//	static void deallocate(T*& ptr)
//	{
//		if (ptr)
//		{
//			delete[] ptr;
//			ptr = NULL;
//
//		}
//
//	}
//	static void deallocate(T**& ptr, int size)
//	{
//		if (ptr)
//		{
//			for (int i = 0; i < size; i++)
//			{
//				if (ptr[i])
//				{
//					delete ptr[i];
//					ptr[i] = NULL;
//				}
//
//				
//			}
//			delete[] ptr;
//			ptr = NULL;
//
//		}
//
//	}
//};
//class Object//---------------------------------------Object------------------------------------------
//{
//protected:
//	char* ID;
//public:
//	Object()
//	{
//		ID = NULL;
//	}
//	virtual void AddposttoTimeline(Post* ptr) {};
//	virtual void printlist() {};
//	virtual void printname() {};
//	virtual ~Object()   //maybe virtual to be implemented here firstly child element will be popped due to virtual and then parent
//	{
//		delete[] ID;
//
//	}
//
//};
//
////-----------------------------------------            CLASS    DATE            ------------------------------------------------------
//class Date
//{
//private:
//	int day;
//	int month;
//	int year;
//public:
//	static Date currentdate;        //date is being shared everywhere
//	Date()
//	{
//		day = 0;
//		month = 0;
//		year = 0;
//	}
//	void Setcurrentdate(int _day, int _month, int _year)
//	{
//		currentdate.day = _day;
//		currentdate.month = _month;
//		currentdate.year = _year;
//	}
//	bool isLatestPost()
//	{
//		if ((day == currentdate.day || day == currentdate.day - 1) && month == currentdate.month && year == currentdate.year)
//		{
//			return true;
//		}
//		else
//			return false;
//	}
//	void readdatefromfile(ifstream& file)
//	{
//		file >> day >> month >> year;
//	}
//	void printdate()
//	{
//		cout << "(" << day << "/" << month << "/" << year << ")";
//	}
//};
//Date Date::currentdate;
//// //---------------------------------------------   CLASS   ACTIVITY   -------------------------------------------
//class Activity
//{
//private:
//	int type;
//	char* value;
//public:
//	Activity()
//	{
//		type = 0;
//		value = NULL;
//	}
//	void LoadActivity(ifstream& fin)
//	{
//		char temp[50];
//		fin >> type;
//		fin.ignore();
//		fin.getline(temp, 100, '\n');
//		value = Helper::GetStringFromBuffer(temp);
//	}
//	void print()
//	{
//		if (type == 1)
//			cout << " is feeling ";
//		else if (type == 2)
//			cout << " is thinking about ";
//		else if (type == 3)
//			cout << " is making ";
//		else if (type == 4)
//			cout << " is celebrating ";
//		cout << value << endl;
//
//	}
//	~Activity()
//	{
//		Deallocation<char>::deallocate(value);
//	}
//};
////-----------------------------------------------   CLASS   Comment  -----------------------------------------------------------
//class Comment
//{
//private:
//	char* ID;
//	char* Text;
//	Object* Commentby;
//public:
//	Comment()
//	{
//		ID = NULL;
//		Text = NULL;
//		Commentby = NULL;
//	}
//	void readID(ifstream& file)
//	{
//		char temp[20];
//		file >> temp;              //reading ID who has commented
//		ID = Helper::GetStringFromBuffer(temp);
//	}
//	void AddCommentBy(Object* obj)
//	{
//		Commentby = obj;           //adding comment 
//	}
//	void printcomment()
//	{
//		Commentby->printname();
//		cout << " wrote '" << Text << "'.\n";
//	}
//	void Readtext(ifstream& fin)
//	{
//		char temp[100];
//		fin.ignore();
//		fin.getline(temp, 100, '\n');
//		Text = Helper::GetStringFromBuffer(temp);
//
//	}
//	void setcomment(Object* objptr, const char* _text)
//	{
//		Text = Helper::GetStringFromBuffer(_text);
//		Commentby = objptr;
//	}
//	~Comment()
//	{
//		Deallocation<char>::deallocate(ID);
//		Deallocation<char>::deallocate(Text);
//		//Deallocation<Object>::deallocate(Commentby);
//
//	}
//};
////------------------------------------------      Classs POST    ---------------------------------------------------------------
//class Post
//{
//private:
//	int type;
//	int totallikes;
//	int totalcomments;
//	char* ID;
//	char* text;
//	Activity* act;
//	Date* shareddate;
//	Object* sharedby;
//	Object** likedby;
//	Comment** comments;
//
//public:
//	Post()
//	{
//		type = 0;
//		comments = 0;
//		ID = NULL;
//		act = NULL;
//		text = NULL;
//		shareddate = new Date;
//		sharedby = new Object;
//		totallikes = 0;
//		act = NULL;
//		likedby = NULL;
//		totalcomments = 0;
//	}
//	char* GetID()
//	{
//		return ID;
//	}
//	void loadpostfromfile(ifstream& file)
//	{
//		file >> type;
//		char temp[100];
//		/*
//		file >> temp;
//		ptr = new Activity;
//		ptr = Helper::GetStringFromBuffer(temp);*/
//
//		file >> temp;
//		ID = Helper::GetStringFromBuffer(temp);
//
//		shareddate->readdatefromfile(file);
//		file.ignore();
//
//		file.getline(temp, 100, '\n');
//		text = Helper::GetStringFromBuffer(temp);
//
//		if (type == 2)
//		{
//			act = new Activity;
//			act->LoadActivity(file);
//		}
//	}
//
//	void setsharedby(Object* sharedbyptr)
//	{
//		sharedby = sharedbyptr;
//	}
//
//	void SetLkes(Object* ptr)
//	{
//		if (totallikes == 0)
//		{
//			likedby = new Object * [10];
//		}
//		if (totallikes < 10)
//		{
//			likedby[totallikes++] = ptr;
//		}
//		else
//			cout << "CANNOT ADD FURTHER LIKES" << endl;
//	}
//	void addcomments(Comment* comptr)
//	{
//		if (totalcomments == 0)
//		{
//			comments = new Comment * [10];
//		}
//		if (totalcomments < 10)
//		{
//			comments[totalcomments++] = comptr;
//
//		}
//		else
//			cout << "cannot add further comments" << endl;
//	}
//	void printlastestpost()
//	{
//		if (shareddate->isLatestPost())
//		{
//			sharedby->printname();
//			if (type == 2)
//			{
//				act->print();
//			}
//			else
//				cout << "shared ";
//			cout << "'" << text << "' .\n";
//			for (int i = 0; i < totalcomments; i++)
//			{
//				cout << "\t";
//				comments[i]->printcomment();    //may have error here
//				//------------------------------------------------------------------------------------------------------
//			}
//			cout << endl;
//		}
//	}
//	void viewlikedlist()          //printing like list
//	{
//		for (int i = 0; i < totallikes; i++)
//		{
//			likedby[i]->printlist();
//			cout << endl;
//		}
//	}
//	void printpost()
//	{
//		sharedby->printname();
//		if (type == 2)
//		{
//			act->print();
//		}
//		else
//			cout << "shared '";
//		cout << "' " << text << " '.\n";
//		for (int i = 0; i < totalcomments; i++)
//		{
//			cout << "\t";
//			comments[i]->printcomment();
//		}
//		cout << endl;
//	}
//	void printcomment()
//	{
//		for (int i = 0; i < totalcomments; i++)
//		{
//			comments[i]->printcomment();
//		}
//	}
//	~Post()                 //deallocating here
//	{
//		Deallocation<char>::deallocate(ID);
//		Deallocation<char>::deallocate(text);
//		if (act)
//			delete act;
//		Deallocation<Date>::deallocate(shareddate);
//		Deallocation<Comment>::deallocate(comments, totalcomments);
//		if (likedby)
//			delete[] likedby;
//
//	}
//
//};
//
//
////-----------------------------------------------   CLASS   PAGES    -----------------------------------------------------------
//class Pages : public Object
//{
//
//
//private:
//	char* TitleofPages;
//	int noofpost;
//	Post** Timeline;
//
//public:
//	Pages()
//	{
//		ID = NULL;
//		TitleofPages = NULL;
//		noofpost = 0;
//		Timeline = NULL;
//
//	}
//
//	char* getpageID()
//	{
//		return ID;
//	}
//	void loadpages(ifstream& file)
//	{
//		char temp[50];
//
//
//		file >> temp;   //reading ID of page
//		ID = Helper::GetStringFromBuffer(temp);
//
//		file.getline(temp, 50, '\n');// reading whole line bcoz name can of 3 fname mname lname
//		// \n for moving pointer to next line 
//		TitleofPages = Helper::GetStringFromBuffer(temp);
//
//	}
//	void printpages()
//	{
//		cout << ID << " " << TitleofPages << endl;
//	}void printname()
//	{
//		cout << TitleofPages;
//	}
//	void AddposttoTimeline(Post* ptr)
//	{
//		if (noofpost == 0)
//		{
//			Timeline = new Post * [10];
//		}
//		if (noofpost < 10)
//		{
//			Timeline[noofpost] = ptr;
//			noofpost++;
//		}
//		else
//			cout << "CANNOT ADD FURTHER POST TO TIMELINE" << endl;
//
//	}
//	void printTimeLine()
//	{
//		for (int i = 0; i < noofpost; i++)
//		{
//			Timeline[i]->printlastestpost();
//		}
//	}
//	void printlist()
//	{
//		cout << ID << " " << TitleofPages;
//	}
//	~Pages()
//	{
//		Deallocation<char>::deallocate(TitleofPages);
//		Deallocation<Post>::deallocate(Timeline, noofpost);
//	}
//
//};
////--------------------------------------------USer class------------------------------------------
//class Users : public Object
//{
//private:
//	//int nooffriends;
//	int totallikedpages;
//	int totalfriends;
//	int noofposts;
//	char* firstname;
//	char* lastname;
//	Users** FriendList;
//	Pages** Likedpages;
//	Post** Timeline;
//
//public:
//	Users()
//	{
//		ID = NULL;
//		firstname = NULL;
//		lastname = NULL;
//		FriendList = NULL;
//		Likedpages = NULL;
//		totalfriends = 0;
//		totallikedpages = 0;
//		Timeline = NULL;
//		noofposts = 0;
//
//	}
//
//	char* getfirstname()
//	{
//		return firstname;
//	}
//	char* getID()
//	{
//		return ID;
//	}
//	void loaduser(ifstream& fin,char** &tempFriendIds)
//	{
//		char temp[50];
//		fin >> temp;
//		ID = Helper::GetStringFromBuffer(temp);
//
//		fin >> temp;
//		firstname = Helper::GetStringFromBuffer(temp);
//
//		fin >> temp;
//		lastname = Helper::GetStringFromBuffer(temp);
//
//		int i = 0;
//		tempFriendIds = new char* [10];
//
//		while (temp[0] != '-')//works until it find delimiter and also stores the delimiter
//		{
//			fin >> temp;
//			tempFriendIds[i] = Helper::GetStringFromBuffer(temp);
//			i++;
//		}
//
//	}
//	void addusertoLikedPages(Pages* ptr)
//	{
//		if (totallikedpages == 0)
//		{
//			Likedpages = new Pages * [10];
//		}
//		Likedpages[totallikedpages++] = ptr;
//	}
//	void friendassociation(Users* ptr)
//	{
//		if (totalfriends == 0)
//		{
//			FriendList = new Users * [10];
//		}
//		FriendList[totalfriends++] = ptr;
//	}
//	void AddposttoTimeline(Post* ptr)
//	{
//		if (noofposts == 0)
//			Timeline = new Post * [10];
//		if (noofposts < 10) {
//			Timeline[noofposts] = ptr;
//			noofposts++;
//		}
//		else
//			cout << "cannot addup posts to timeline" << endl;
//	}
//	void printlist()
//	{
//		cout << ID << "-" << firstname << " " << lastname << endl;
//	}
//	void printTimeLine()
//	{
//		for (int i = 0; i < noofposts; i++)
//		{
//			Timeline[i]->printpost();
//		}//continue here
//	}
//	void printusers()
//	{
//		cout << ID << " " << firstname << " " << lastname << endl;
//	}
//	void viewfriendlist() // Printing friends
//	{
//		for (int i = 0; i < totalfriends; i++)
//		{
//			//cout << FriendList[i]->ID << endl;
//			FriendList[i]->printusers();
//		}
//	}
//	void viewlikedpages()
//	{
//		for (int i = 0; i < totallikedpages; i++)
//		{
//			Likedpages[i]->printpages();
//		}
//	}
//	int gettotalfriends()
//	{
//		return totalfriends;
//	}
//	void printtimelineofcurrentuser()
//	{
//		for (int i = 0; i < noofposts; i++)
//		{
//			Timeline[i]->printpost();
//		}
//	}
//	void homeview()
//	{
//		for (int i = 0; i < totalfriends; i++)
//		{
//			FriendList[i]->printTimeLine();
//		}
//		for (int i = 0; i < totallikedpages; i++)
//		{
//			Likedpages[i]->printTimeLine();           //may have eerror here ==================================================
//		}
//	}
//	void printname()
//	{
//		cout << firstname << " " << lastname;
//	}
//	void printfriendlist()
//	{
//		for (int i = 0; i < totalfriends; i++)
//		{
//			FriendList[i]->printfriendlist();
//			cout << endl;
//		}
//	}
//	~Users()
//	{
//		Deallocation<char>::deallocate(ID);
//		Deallocation<char>::deallocate(firstname);
//		Deallocation<char>::deallocate(lastname);
//		Deallocation<Post>::deallocate(Timeline, noofposts);
//		delete[] FriendList;
//		delete[] Likedpages;
//
//	}
//};
////---------------------------------------------   Class   Memory     -------------------------------------------
////class Memory : public Post
////{
////private:
////	char* extratext;
////	Post* orignalpost;
////	Date systemdate;
////public:
////	Memory()
////	{
////		orignalpost = NULL;
////		extratext = NULL;
////	}
////	void sharememory()
////	{
////		orignalpost=
////	}
////};
////---------------------------------------------   CLASS   FACEBOOK   -------------------------------------------
//class Facebook
//{
//private:
//	static int totalpages;
//	static int totalusers;
//	static int totalposts;
//	static int totalcomments;
//	Pages** PageList;
//	Users** UserList;
//	Users* currentuser;
//	Post** PostList;
//	Comment** CommentList;
//
//public:
//	Users* searchuserbyID(const char* ptr)
//	{
//		for (int i = 0; i < totalusers; i++)
//		{
//			bool flag = strcmp(ptr, UserList[i]->getID());
//			if (flag == 0)
//			{
//				return UserList[i];
//			}
//		}
//	}
//	Pages* searchpagebyID(const char* ptr)
//	{
//		for (int i = 0; i < totalpages; i++)
//		{
//			bool flag = strcmp(ptr, PageList[i]->getpageID());
//			if (flag == 0)
//			{
//				return PageList[i];
//			}
//		}
//	}
//	Post* searchpostbyID(const char* ptr)
//	{
//		for (int i = 0; i < totalposts; i++)
//		{
//			bool flag = strcmp(ptr, PostList[i]->GetID());
//			if (flag == 0)
//			{
//				return PostList[i];
//			}
//		}
//	}
//	Object* searchpageoruser(char* temp)
//	{
//		Object* ptr = 0;
//		if (temp[0] == 'u')
//		{
//			ptr = searchuserbyID(temp);
//		}
//		if (temp[0] == 'p')
//		{
//			ptr = searchpagebyID(temp);
//		}
//		return ptr;
//	}
//	void loaduser(const char* user, const char* page)
//	{
//		ifstream userdata;
//		ifstream pagedata;
//		pagedata.open(page);
//		if (pagedata.is_open())
//		{
//			pagedata >> totalpages;
//			PageList = new Pages * [totalpages];        //loading pages here
//			for (int i = 0; i < totalpages; i++)
//			{
//				PageList[i] = new Pages;
//				PageList[i]->loadpages(pagedata);
//
//			}
//		}
//		else
//			cout << "ERROR WHILE OPENING PAGES FILR" << endl;
//		pagedata.close();
//		userdata.open(user);
//		if (userdata.is_open())
//		{
//			userdata >> totalusers;
//			UserList = new Users * [totalusers];       //loading users here
//			char*** tempfriendlist = new char** [totalusers];
//			for (int i = 0; i < totalusers; i++)
//			{
//				UserList[i] = new Users;
//				UserList[i]->loaduser(userdata, tempfriendlist[i]);
//
//				char temp[10] = {};
//				while (temp[0] != '-')
//				{
//					userdata >> temp;
//					if (temp[0] != '-')
//					{
//						Pages* ptr = searchpagebyID(temp);
//						UserList[i]->addusertoLikedPages(ptr);
//
//					}
//				}
//
//			}
//
//
//			//associating freinds
//			for (int i = 0; i < totalusers; i++)
//			{
//				int j = 0;
//				while (tempfriendlist[i][j][0] != '-')
//				{
//					Users* ptr = searchuserbyID(tempfriendlist[i][j]);
//					UserList[i]->friendassociation(ptr);
//					j++;
//				}
//			}
//
//
//			//deallocation of triple pointer
//			for (int i = 0; i < totalusers; i++)
//			{
//				for (int j = 0; j < UserList[i]->gettotalfriends(); j++)
//				{
//					delete tempfriendlist[i][j];
//				}
//				delete tempfriendlist[i];
//			}
//			delete[] tempfriendlist;
//
//		}
//
//
//		else
//		{
//			cout << "ERROR OPENING USERS FILE" << endl;
//		}
//		userdata.close();
//
//	}
//	void loadpost()
//	{
//		ifstream file("Posts.txt");
//		if (file.is_open())
//		{
//			char temp[100];
//			file >> totalposts;
//
//			PostList = new Post * [totalposts];
//
//			for (int i = 0; i < totalposts; i++)
//			{
//				PostList[i] = new Post;
//				PostList[i]->loadpostfromfile(file);
//
//				file >> temp;
//
//				Object* sharedby = NULL;
//				sharedby = searchpageoruser(temp);    //if at first index u then user elseif p then pages;
//				PostList[i]->setsharedby(sharedby);
//				sharedby->AddposttoTimeline(PostList[i]);
//				Object* tempptr = NULL;
//				while (temp[0] != '-')
//				{
//					file >> temp;
//					if (temp[0] != '-')
//					{
//						tempptr = searchpageoruser(temp);
//						PostList[i]->SetLkes(tempptr);
//					}
//				}
//			}
//		}
//		else
//			cout << "POst list cannot be opened";
//
//	}
//	void loadcomments()
//	{
//		ifstream file("Comments.txt");
//		if (file.is_open())
//		{
//			file >> totalcomments;
//			CommentList = new Comment * [totalcomments];
//			for (int i = 0; i < totalcomments; i++)
//			{
//				char temp[100];
//				CommentList[i] = new Comment;
//				CommentList[i]->readID(file);
//
//				file >> temp;
//				Post* postptr;
//
//				postptr = searchpostbyID(temp);
//				postptr->addcomments(CommentList[i]);
//
//				file >> temp;
//				Object* tempobjptr = searchpageoruser(temp);
//				CommentList[i]->AddCommentBy(tempobjptr);
//				CommentList[i]->Readtext(file);
//			}
//		}
//		else
//			cout << "ERROR WHILE OPENING COMMENT FILE";
//	}
//	void setcurrentuser(const char* temp)
//	{
//		currentuser = searchuserbyID(temp);
//	}
//	void viewlikelist(const char* ptr)
//	{
//		Post* currentpost;
//		currentpost = searchpostbyID(ptr);
//		currentpost->viewlikedlist();
//		cout << "Post Liked Successfully By Current User.\n";
//
//	}
//	void printpostcomment(const char* ptr)
//	{
//		Post* tempptr;
//		tempptr = searchpostbyID(ptr);
//		tempptr->printcomment();             //printing postcomment here calling in run
//	}
//	void PostComment(const char* postID, const char* text)
//	{
//		//printpostcomment(postID);
//		Comment* addingcomment = new Comment;
//		addingcomment->setcomment(currentuser, text);
//		Post* ptr = searchpostbyID(postID);
//		ptr->addcomments(addingcomment);
//	}
//	void viewpage(const char* page)
//	{
//		Pages* pptr;
//		pptr = searchpagebyID(page);
//		pptr->printTimeLine();
//	}
//	void Run()
//	{
//		loaduser("User.txt", "Pages.txt");
//		loadpost();
//		loadcomments();
//
//		cout << "Command:\t Set current System Date 15 11 2017\n";
//		cout << "System Date:\t";
//		Date::currentdate.Setcurrentdate(15, 11, 2017);
//		Date::currentdate.printdate();
//		cout << endl;
//
//		for (int i = 0; i < 100; i++)
//		{
//			cout << "_";
//		}
//		cout << endl;
//		setcurrentuser("u7");
//		cout << "Current user is ";
//		currentuser->printname();
//		cout << endl;
//		for (int i = 0; i < 100; i++)
//		{
//			cout << "_";
//		}
//		cout << endl;
//		cout << "Command:\t View Home\n";
//		currentuser->printname();
//		cout << endl;
//		currentuser->homeview();
//		for (int i = 0; i < 100; i++)
//		{
//			cout << "_";
//		}
//		cout << endl;
//		cout << " - Timeline\n\n";
//		currentuser->printTimeLine();
//
//		cout << "Command:\tViewLikedPost(post5)\n";
//		for (int i = 0; i < 100; i++)
//		{
//			cout << "_";
//		}
//		cout << endl;
//		viewlikelist("post5");
//		for (int i = 0; i < 100; i++)
//		{
//			cout << "_";
//		}
//		cout << endl;
//		cout << "Command:\t Like Post(post5)\n";
//		viewlikelist("post5");
//		for (int i = 0; i < 100; i++)
//		{
//			cout << "_";
//		}
//		cout << endl;
//		cout << "Command:\tViewLikedPost(post5)\n";
//		for (int i = 0; i < 100; i++)
//		{
//			cout << "_";
//		}
//		cout << endl;
//		viewlikelist("post5");
//		for (int i = 0; i < 100; i++)
//		{
//			cout << "_";
//		}
//		cout << endl;
//		cout << "COMMENTS" << endl;
//		printpostcomment("post5");
//		/*
//		for (int i = 0; i < totalcomments; i++)
//		{
//			CommentList[i]->printcomment();
//		}*/
//		for (int i = 0; i < 100; i++)
//		{
//			cout << "_";
//		}
//		cout << endl;
//		cout << "COMMAND Post adding comment" << endl;
//		PostComment("post8", "Thanks for the wishes");
//		printpostcomment("post8");
//		for (int i = 0; i < 100; i++)
//		{
//			cout << "_";
//		}
//		cout << endl;
//		cout << "Command:                   ViewPage(p1)" << endl;
//		viewpage("p1");
//		for (int i = 0; i < 100; i++)
//		{
//			cout << "_";
//		}
//		cout << endl;
//
//	//	setting up enext user from here
//		cout << "Command:                Set current user u11" << endl;
//		setcurrentuser("u11");
//		currentuser->printname();
//		cout << " successfully set as Current User" << endl;
//		for (int i = 0; i < 100; i++)
//		{
//			cout << "_";
//		}
//		cout << endl;
//		cout << "Command: ViewHome" << endl;
//		currentuser->homeview();
//		for (int i = 0; i < 100; i++)
//		{
//			cout << "_";
//		}
//		cout << endl;
//		cout << "Command: ViewTimeline" << endl;
//		currentuser->printTimeLine();
//		for (int i = 0; i < 100; i++)
//		{
//			cout << "_";
//		}
//		cout << endl;
//		
//	}
//	~Facebook()
//	{
//		Deallocation<Users>::deallocate(UserList, totalusers);
//		/*for (int i = 0; i < totalusers; i++)
//			delete UserList[i];
//		delete[] UserList;*/
//		Deallocation<Pages>::deallocate(PageList, totalpages);
//		/*for (int i = 0; i < totalpages; i++)
//			delete pageList[i];
//		delete[] pageList;*/
//	
//
//	}
//};
//int Facebook::totalpages = 0;
//int Facebook::totalusers = 0;
//int Facebook::totalposts = 0;
//int Facebook::totalcomments = 0;
//
//void main()
//{
//	system("color9f");
//	{
//		Facebook fb;
//		fb.Run();
//	}
//	system("pause");
//
//}