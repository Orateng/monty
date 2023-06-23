#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void add(stack_t **head, unsigned int counter)
{
        stack_t *h;
        int len = 0, aux;

        h = *head;
        while (h)
        {
                h = h->next;
                len++;
        }
        if (len < 2)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", counter);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        h = *head;
        aux = h->n + h->next->n;
        h->next->n = aux;
        *head = h->next;
        free(h);
}

/**
  *sub- sustration
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void sub(stack_t **head, unsigned int counter)
{
        stack_t *aux;
        int sus, nodes;

        aux = *head;
        for (nodes = 0; aux != NULL; nodes++)
                aux = aux->next;
        if (nodes < 2)
        {
                fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        aux = *head;
        sus = aux->next->n - aux->n;
        aux->next->n = sus;
        *head = aux->next;
        free(aux);
}

/**
 * div_num - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void div_num(stack_t **head, unsigned int counter)
{
        stack_t *h;
        int len = 0, aux;

        h = *head;
        while (h)
        {
                h = h->next;
                len++;
        }
        if (len < 2)
        {
                fprintf(stderr, "L%d: can't div, stack too short\n", counter);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        h = *head;
        if (h->n == 0)
        {
                fprintf(stderr, "L%d: division by zero\n", counter);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        aux = h->next->n / h->n;
        h->next->n = aux;
        *head = h->next;
        free(h);
}
