#include "monty.h"
/**
  *nop- nothing
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void nop(stack_t **head, unsigned int counter)
{
        (void) counter;
        (void) head;
}

/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void mod(stack_t **head, unsigned int counter)
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
                fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
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
        aux = h->next->n % h->n;
        h->next->n = aux;
        *head = h->next;
        free(h);
}

/**
 * pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pchar(stack_t **head, unsigned int counter)
{
        stack_t *h;

        h = *head;
        if (!h)
        {
                fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        if (h->n > 127 || h->n < 0)
        {
                fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        printf("%c\n", h->n);
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pstr(stack_t **head, unsigned int counter)
{
        stack_t *h;
        (void)counter;

        h = *head;
        while (h)
        {
                if (h->n > 127 || h->n <= 0)
                {
                        break;
                }
                printf("%c", h->n);
                h = h->next;
        }
        printf("\n");
}
