#pragma once

#define MAX_ARTICLE_NAME 128

//class Article
typedef struct _article
{
	char name[20];
	int quantity;
	float price;

}Article;
typedef struct _article* ArticlePointer;

// Constructor and Deconstructor
int ArticleConstructor(ArticlePointer _this, const char* name, int quantity, float price); 
int ArticleConstructorClear(ArticlePointer _this); // for head element
int ArticleDeconstructor(ArticlePointer _this);

// Methods
int PrintArticleData(ArticlePointer _this);