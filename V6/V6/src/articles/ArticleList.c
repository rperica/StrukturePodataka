#include "ArticleList.h"
#include "tools/Assert.h"

#include "stdlib.h"
#include "string.h"

static ArticlePosition NewArticleElement(const char* name, int quantity, float price);
static int ClearAfterArticle(ArticlePosition position);
static int InsertArticleSorted(ArticlePosition head, ArticlePosition newElement);
static int InsertAfterArticle(ArticlePosition position, ArticlePosition newElement);

int CreateAndInsertArticle(ArticlePosition head, const char* name, int quantity, float price)
{
	ArticlePosition article = NewArticleElement(name, quantity, price);
	InsertArticleSorted(head, article);

	return 0; // !
}

int ClearArticles(ArticlePosition head)
{
	for (; head->nextArticle != NULL;)
	{
		ClearAfterArticle(head);
	}

	return 0; // !
}

int PrintArticles(ArticlePosition head)
{
	ArticlePosition first = head->nextArticle;

	for (; first != NULL; first = first->nextArticle)
	{
		PrintArticleData(&first->article);
	}

	return 0; // !
}

static ArticlePosition NewArticleElement(const char* name, int quantity, float price)
{
	ArticlePosition newElement = NULL;

	ASSERT(newElement = (ArticlePosition)malloc(sizeof(ArticleElement)));

	ArticleConstructor(&newElement->article, name, quantity, price);
	newElement->nextArticle = NULL; 

	return newElement;
}

static int ClearAfterArticle(ArticlePosition position)
{
	ArticlePosition garbage = position->nextArticle;
	position->nextArticle = garbage->nextArticle;

	//ArticleDeconstructor(&garbage->article); 
	free(garbage);

	return 0; // !
}

static int InsertArticleSorted(ArticlePosition head, ArticlePosition newElement)
{
	ArticlePosition temp = head;

	for (; temp->nextArticle != NULL && strcmp(temp->nextArticle->article.name, newElement->article.name) < 0; temp = temp->nextArticle) {}

	InsertAfterArticle(temp, newElement);

	return 0; // !
}

static int InsertAfterArticle(ArticlePosition position, ArticlePosition newElement)
{
	newElement->nextArticle = position->nextArticle;
	position->nextArticle = newElement;

	return 0; // !
}