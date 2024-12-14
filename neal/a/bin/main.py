import turtle
bob=turtle.Turtle()
screen=turtle.Screen()
bob.goto(0,0)
def square():
    for i in range(4):
        bob.forward(50)
        bob.right(90)
screen.onkey(square,"d")
screen.listen()
