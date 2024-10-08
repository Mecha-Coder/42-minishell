#include "eval.h"

int main(int ac, char **av)
{
    t_node *root;

    if (ac == 2 && av[1][0])
    {
        root = create_node();
        root->s = av[1];
        build_tree(root);
        
        visualize_tree(root, 0);
        //detail_node(root);
        
        printf("\nAnswer: %d\n", evaluate(root));
        destroy_tree(root);
    }
    else
        printf("Invalid input\n");
    return (0);
}

/*Test sample

./compute "5 + 6 * 3"
./compute "((5 - 6) + (3 + 6))"
./compute "(63 + (3 + 6))"
./compute "(324 * 44)"
./compute "34 - (63 + (3 + 6))"
./compute "456 + 324 + 44"
./compute "456 * (324 * 44)"
./compute "5*5*5"
./compute "45 + 100 / (5 * 20) - 2"
*/