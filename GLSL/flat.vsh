attribute highp vec4 v_vertex;
attribute highp vec4 v_color;
uniform highp mat4 u_mvp;
varying highp vec4 f_color;

void main(void)
{
    f_color = v_color;
    gl_Position = u_mvp* v_vertex;
}

