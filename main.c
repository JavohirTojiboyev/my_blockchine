#include "main.h"
int main() {
    nodelist *nodes = (nodelist*)malloc(sizeof(nodelist));
    bool is_file = access(DB, F_OK ) != -1;
    if(is_file) {
        printf("Restoring From Backup\n");
        read_linked_list(&nodes);
    } else {
        printf("No Backup Found: Starting New Blockchain\n");
        nodes = NULL;
    }
        
    while(true) {
        char is_syn = is_sync(&nodes) ? 's' : '-';
        printf("[%c%d]>", is_syn, count_nodes(&nodes));
        fflush(stdout);
        char* s_cmd = my_readline(0);
        if(like(s_cmd, "") OR like(s_cmd, " ") OR s_cmd==0) {
            break;
        }
        char* clear_cmd = malloc(strlen(s_cmd)+1);
        trim(clear_cmd, s_cmd);
        string_array* cmd_arr = my_split(clear_cmd, " ");
        int res = blockchain(&nodes, cmd_arr);
        if(res == EXIT)
            break;
    }
    return 0;
}
