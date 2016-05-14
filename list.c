typedef struct node node;
typedef struct list list;

struct node{
  node * previous_node;
  node * next_node;
  void * value;
};

struct list{
  node * head_node;
  node * tail_node;
};

int main(int argc, char** argv){
  return 0;
}
