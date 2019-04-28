/* hello.c -- initialize the toolkit using an application context 
** and a toplevel shell widget, then create a pushbutton that says
** Hello using the varargs interface. 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#include <X11/Intrinsic.h>
#include <Xm/Xm.h>
#include <Xm/Label.h>


#include <Xm/PushB.h>


main (int argc, char *argv[])
{
    Widget           toplevel, button;
    XtAppContext     app;
    void             button_pushed(Widget, XtPointer, XtPointer);
    XmString         label;
    Arg              args[2];

    XtSetLanguageProc (NULL, NULL, NULL);
    toplevel = XtVaOpenApplication (&amp;app, "Hello", NULL, 0, &amp;argc, argv,
                                    NULL,sessionShellWidgetClass, NULL);    
    label = XmStringCreateLocalized ("Push here to say hello");
    XtSetArg(args[0], XmNlabelString, label);
    button = XmCreatePushButton (toplevel, "pushme", args, 1);
    XmStringFree (label);
    XtAddCallback (button, XmNactivateCallback, button_pushed, NULL);
    XtManageChild (button);
    XtRealizeWidget (toplevel);
    XtAppMainLoop (app);
}

void button_pushed (Widget widget, XtPointer client_data, XtPointer call_data)
{
    printf ("Hello Yourself!\n");
}




