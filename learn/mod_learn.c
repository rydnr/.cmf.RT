/* 
**  mod_learn.c -- Apache sample learn module
**  [Autogenerated via ``apxs -n learn -g'']
**
**  To play with this sample module first compile it into a
**  DSO file and install it into Apache's modules directory 
**  by running:
**
**    $ apxs -c -i mod_learn.c
**
**  Then activate it in Apache's apache2.conf file for instance
**  for the URL /learn in as follows:
**
**    #   apache2.conf
**    LoadModule learn_module modules/mod_learn.so
**    <Location /learn>
**    SetHandler learn
**    </Location>
**
**  Then after restarting Apache via
**
**    $ apachectl restart
**
**  you immediately can request the URL /learn and watch for the
**  output of this module. This can be achieved for instance via:
**
**    $ lynx -mime_header http://localhost/learn 
**
**  The output should be similar to the following one:
**
**    HTTP/1.1 200 OK
**    Date: Tue, 31 Mar 1998 14:42:22 GMT
**    Server: Apache/1.3.4 (Unix)
**    Connection: close
**    Content-Type: text/html
**  
**    The sample page from mod_learn.c
*/ 
#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "ap_config.h"

static void print_string(const char *name, char *value, request_rec *r) {
    ap_rputs("<dt>", r);
    ap_rputs(name, r);
    ap_rputs("</dt>\n", r);
    ap_rputs("<dd>", r);
    if (value == NULL) {
        ap_rputs("null", r);
    } else {
        ap_rputs(value, r);
    }
    ap_rputs("</dd>\n", r);
}

static void print_pool(request_rec *r) {
    print_string("r->pool", "TODO", r);
}

static void print_connection(request_rec *r) {
    print_string("r->connection", "TODO", r);
}

static void print_server(request_rec *r) {
    print_string("r->server", "TODO", r);
}

static void print_next(request_rec *r) {
    print_string("r->next", "TODO", r);
}

static void print_prev(request_rec *r) {
    print_string("r->prev", "TODO", r);
}

static void print_main(request_rec *r) {
    print_string("r->main", "TODO", r);
}

static void print_allowed_xmethods(request_rec *r) {
    print_string("r->allowed_xmethods", "TODO", r);
}

static void print_allowed_methods(request_rec *r) {
    print_string("r->allowed_methods", "TODO", r);
}

static void print_sent_bodyct(request_rec *r) {
    print_string("r->sent_bodyct", "TODO", r);
}

static void print_bytes_sent(request_rec *r) {
    print_string("r->bytes_sent", "TODO", r);
}

static void print_mtime(request_rec *r) {
    print_string("r->mtime", "TODO", r);
}

static void print_clength(request_rec *r) {
    print_string("r->clength", "TODO", r);
}

static void print_kept_body(request_rec *r) {
    print_string("r->kept_body", "TODO", r);
}

static void print_body_table(request_rec *r) {
    print_string("r->body_table", "TODO", r);
}

static void print_remaining(request_rec *r) {
    print_string("r->remaining", "TODO", r);
}

static void print_read_length(request_rec *r) {
    print_string("r->read_length", "TODO", r);
}

static void print_headers_in(request_rec *r) {
    print_string("r->headers_in", "TODO", r);
}

static void print_headers_out(request_rec *r) {
    print_string("r->headers_out", "TODO", r);
}

static void print_err_headers_out(request_rec *r) {
    print_string("r->err_headers_out", "TODO", r);
}

static void print_subprocess_env(request_rec *r) {
    print_string("r->subprocess_env", "TODO", r);
}

static void print_notes(request_rec *r) {
    print_string("r->notes", "TODO", r);
}

static void print_handler(request_rec *r) {
    print_string("r->handler", "TODO", r);
}

static void print_content_languages(request_rec *r) {
    print_string("r->content_languages", "TODO", r);
}

static void print_per_dir_config(request_rec *r) {
    print_string("r->per_dir_config", "TODO", r);
}

static void print_request_config(request_rec *r) {
    print_string("r->request_config", "TODO", r);
}

static void print_log(request_rec *r) {
    print_string("r->log", "TODO", r);
}

static void print_htaccess(request_rec *r) {
    print_string("r->htaccess", "TODO", r);
}

static void print_output_filters(request_rec *r) {
    print_string("r->output_filters", "TODO", r);
}

static void print_input_filters(request_rec *r) {
    print_string("r->input_filters", "TODO", r);
}

static void print_proto_output_filters(request_rec *r) {
    print_string("r->proto_output_filters", "TODO", r);
}

static void print_proto_input_filters(request_rec *r) {
    print_string("r->proto_input_filters", "TODO", r);
}

static void print_invoke_mix(request_rec *r) {
    print_string("r->invoke_mix", "TODO", r);
}

static void print_parsed_uri(request_rec *r) {
    print_string("r->parsed_uri", "TODO", r);
}

static char * itoa(int value) {
    int LENGTH = (CHAR_BIT * sizeof(int) - 1) / 3 + 2;
    char result[LENGTH];
    snprintf(result, LENGTH, "%d", value);
    return &result;
}

static void print_int(char *name, int value, request_rec *r) {
    ap_rputs("<dt>", r);
    ap_rputs(name, r);
    ap_rputs("</dt><dd>", r);
    ap_rputs(itoa(value), r);
    ap_rputs("</dd>\n", r);
}

static void print_request_time(request_rec *r) {
    print_string("r->request_time", "TODO", r);
}

static int learn_handler(request_rec *r)
{
    if (strcmp(r->handler, "learn")) {
        return DECLINED;
    }

    r->content_type = "text/html";      

    if (!r->header_only) {
        ap_rputs("<html><head><title>Learn module</title></head><body><dl>\n", r);
        print_pool(r);
        print_connection(r);
        print_server(r);
        print_next(r);
        print_prev(r);
        print_main(r);
        print_string("r->the_request", r->the_request, r);
        print_int("r->assbackwards", r->assbackwards, r);
        print_int("r->proxyreq", r->proxyreq, r);
        print_int("r->header_only", r->header_only, r);
        print_int("r->proto_num", r->proto_num, r);
        print_string("r->protocol", r->protocol, r);
        print_string("r->hostname", r->hostname, r);
        print_request_time(r);
        print_string("r->status_line", r->status_line, r);
        print_int("r->status", r->status, r);
        print_int("r->method_number", r->method_number, r);
        print_string("r->method", r->method, r);
        print_int("r->allowed", r->allowed, r);
        print_allowed_xmethods(r);
        print_allowed_methods(r);
        print_sent_bodyct(r);
        print_bytes_sent(r);
        print_mtime(r);
        print_string("r->range", r->range, r);
        print_clength(r);
        print_int("r->chunked", r->chunked, r);
        print_int("r->read_body", r->read_body, r);
        print_int("r->read_chunked", r->read_chunked, r);
        print_int("r->expecting_100", r->expecting_100, r);
        print_kept_body(r);
        print_body_table(r);
        print_remaining(r);
        print_read_length(r);
        print_headers_in(r);
        print_headers_out(r);
        print_err_headers_out(r);
        print_subprocess_env(r);
        print_notes(r);
        print_string("r->content_type", r->content_type, r);
        print_handler(r);
        print_string("r->content_encoding", r->content_encoding, r);
        print_content_languages(r);
        print_string("r->vlist_validator", r->vlist_validator, r);
        print_string("r->user", r->user, r);
        print_string("r->ap_auth_type", r->ap_auth_type, r);
        print_string("r->unparsed_uri", r->unparsed_uri, r);
        print_string("r->uri", r->uri, r);
        print_string("r->filename", r->filename, r);
        print_string("r->canonical_filename", r->canonical_filename, r);
        print_string("r->path_info", r->path_info, r);
        print_string("r->args", r->args, r);
        print_int("r->used_path_info", r->used_path_info, r);
        print_int("r->eos_sent", r->eos_sent, r);
        print_per_dir_config(r);
        print_request_config(r);
        print_log(r);
        print_string("r->log_id", r->log_id, r);
        print_htaccess(r);
        print_output_filters(r);
        print_input_filters(r);
        print_proto_output_filters(r);
        print_proto_input_filters(r);
        print_int("r->no_cache", r->no_cache, r);
        print_int("r->no_local_copy", r->no_local_copy, r);
        print_invoke_mix(r);
        print_parsed_uri(r);
        
        print_string("r->useragent_ip", r->useragent_ip, r);
        ap_rputs("</dl></body></html>\n", r);
    }
    return OK;
}

static void learn_register_hooks(apr_pool_t *p)
{
    ap_hook_handler(learn_handler, NULL, NULL, APR_HOOK_MIDDLE);
}

/* Dispatch list for API hooks */
module AP_MODULE_DECLARE_DATA learn_module = {
    STANDARD20_MODULE_STUFF, 
    NULL,                  /* create per-dir    config structures */
    NULL,                  /* merge  per-dir    config structures */
    NULL,                  /* create per-server config structures */
    NULL,                  /* merge  per-server config structures */
    NULL,                  /* table of config file commands       */
    learn_register_hooks  /* register hooks                      */
};

