;;; -*-scheme-*-

(debug-set! maxdepth 100000)
(debug-set! stack    2000000)

(define-module (g-wrapped gw-core-utils-spec))

(use-modules (g-wrap))
(use-modules (g-wrap simple-type))

(use-modules (g-wrap gw-standard-spec))
(use-modules (g-wrap gw-wct-spec))
(use-modules (g-wrap gw-glib-spec))

(let ((ws (gw:new-wrapset "gw-core-utils")))

  (gw:wrapset-depends-on ws "gw-standard")
  (gw:wrapset-depends-on ws "gw-wct")
  (gw:wrapset-depends-on ws "gw-glib")

  (gw:wrapset-set-guile-module! ws '(g-wrapped gw-core-utils))

  (gw:wrapset-add-cs-declarations!
   ws
   (lambda (wrapset client-wrapset)
     (list
      "#include <core-utils.h>\n"
      "#include <gnc-gconf-utils.h>\n"
      "#include <gnc-hooks.h>\n")))

  (gw:wrap-function
   ws
   'gnc:gconf-get-bool
   '<gw:bool>
   "gnc_gconf_get_bool_no_error"
   '(((<gw:mchars> caller-owned) section)
     ((<gw:mchars> caller-owned) name))
   "Get a boolean value from gconf.")

  (gw:wrap-function
   ws
   'gnc:run-c-hook
   '<gw:void>
   "gnc_run_c_hook"
   '(((<gw:mchars> caller-owned) name) (<gw:void*> data))
   "Run a callback hook in the C domain.")
)
