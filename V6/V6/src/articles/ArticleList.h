#pragma once

#include "Article.h"

struct _articleList;
typedef struct _articleList* ArticlePosition;
typedef struct _articleList
{
	Article article; // object
	ArticlePosition nextArticle;

}ArticleElement;

int CreateAndInsertArticle(ArticlePosition head, const char* name, int quantity, float price);
int ClearArticles(ArticlePosition head);

int PrintArticles(ArticlePosition head);