# 1 -- Introduction
Below you have your editor (left) and the preview (right). The preview lets you see the output of whatever code is in the editor, this helps you learn by seeing what you have done. What you are reading now are the instructions for your lesson. The submit button, at the bottom, will only react if you got the answer correct. Pay attention to the editor, it will tell you when something is wrong. Type done into the editor and press submit to move on.
## Answer:
done

# 2 -- What is HTML?
HTML allows you to define parts of a website, but it can only do so much. In later lessons we will learn how to style HTML so you can make your website look how you want it to, but for now, the basics. The first thing we need to tell The Browser that we are using HTML5 with the \<DOCTYPE\> element. An element is what tells The Browser what you want to display. They start with \<elementname\> and end with \</elementname\>, we call these tags. The first is the opening tag, and the second is the closing tag, but not all elements have a closing tag, like the \<DOCTYPE\> element. Speaking of the \<DOCTYPE\> element, it looks like this: \<!DOCTYPE html\> and shoud be put at the start of all files. Unless I tell you, assume all elements have an opening and closing tag.
## Answer:
\<!DOCTYPE html\>

# 3 -- More Boilerplate
Unfortunately, \<DOCTYPE\> isn't the only thing required in a document before we start seeing progress. We also need the following after the \<DOCTYPE\> element:
\<html\>
\<head\>
\</head\>
\<body\>
\</body\>
\</html\>
The html element tells The Browser where the actual code starts and ends. This is called boilerplate code, we need this because computers are dumb and need to be told exactly what to do. Programming Languages take care of most boilerplate code, but they can only do so much. The other elements will be explained in further detail when they are relevant, just know you need them.
## Code:
\<!DOCTYPE html\>
## Answer:
\<!DOCTYPE html\>
\<html\>
  \<head\>
  \</head\>
  \<body\>
  \</body\>
\</html\>

# 4 -- Name It With A Title
As I said last lesson, the other elements will be explained in the next lessons and it is time for me to explain the \<head\> element. The \<head\> element contains metadata for your page including, the title. The \<title\> element lets you assign the title of the page. When you write a normal page, you will see the name of the tab change but not with my editor. Put \<title\>Dog Photos\</title\> in between the \<head\> tags.
## Code:
\<!DOCTYPE html\>
\<html\>
  \<head\>
  \</head\>
  \<body\>
  \</body\>
\</html\>
## Answer:
\<!DOCTYPE html\>
\<html\>
  \<head\>
    \<title\>Dog Photos\</title\>
  \</head\>
  \<body\>
  \</body\>
  \</html\>

# 5 -- Now Some Content
Time to start building the actual page. Although you could just type between the \<body\> tags, or even in a blank file, it doesn't allow you to do much with the page. To add some content, we use a paragraph tag: \<p\>. Tags can contain text or other tags, as long as they have a closing tag. Between the \<body\> tags, add a paragraph containing: Dogs are great pets, here are some pictures of mine!
## Code:
\<!DOCTYPE html\>
\<html\>
  \<head\>
    \<title\>Dog Photos\</title\>
  \</head\>
  \<body\>
  \</body\>
\</html\>
## Answer:
\<!DOCTYPE html\>
\<html\>
  \<head\>
    \<title\>Dog Photos\</title\>
  \</head\>
  \<body\>
    \<p\>Dogs are great pets, here are some pictures of mine!\</p\>
  \</body\>
\</html\>

# 6 -- Headers
I realized that I haven't explained the \<body\> element yet. It's very simple, that's where your content goes. Anyway...Headers, the visual organization of your content. We have six levels, \<h1\> through \<h6\>. The lower the number, the bigger the text and the higher level header. \<h1\> is a title header and each below it level gives you more organization for your page. All except the lowest 2 or 3 levels, they are the same size as, or smaller than, the \<p\> text. Oh, about titles, let's add one before \<p\> that's the same as the page title.
## Code:
\<!DOCTYPE html\>
\<html\>
  \<head\>
    \<title\>Dog Photos\</title\>
  \</head\>
  \<body\>
    \<p\>Dogs are great pets, here are some pictures of mine!\</p\>
  \</body\>
\</html\>
## Answer:
\<!DOCTYPE html\>
\<html\>
  \<head\>
    \<title\>Dog Photos\</title\>
  \</head\>
  \<body\>
    \<h1\>Dog Photos\</h1\>
    \<p\>Dogs are great pets, here are some pictures of mine!\</p\>
  \</body\>
\</html\>

# 7 -- More Headers
Tired of how slow this is yet, how many parts there are? Me too, but I don't want to leave anything out so you learn how to build a page but also learn common terms used in coding. I can only pack more content into later lessons if everything is explained early on. Anyway, lets add a section for photos using a \<h2\> element with the text: Photos
## Code:
\<!DOCTYPE html\>
\<html\>
  \<head\>
    \<title\>Dog Photos\</title\>
  \</head\>
  \<body\>
    \<h1\>Dog Photos\</h1\>
    \<p\>Dogs are great pets, here are some pictures of mine!\</p\>
  \</body\>
\</html\>
## Answer:
\<!DOCTYPE html\>
\<html\>
  \<head\>
    \<title\>Dog Photos\</title\>
  \</head\>
  \<body\>
    \<h1\>Dog Photos\</h1\>
    \<p\>Dogs are great pets, here are some pictures of mine!\</p\>
    \<h2\>Photos\<h2\>
  \</body\>
\</html\>

# 8 - Finally, Some Dog Pictures
Ok, time to add some photos. To avoid any copyright issues, these will be pictures of my dogs. To add an image, you need an <img> element. This is one of them tags that don't close, so keep that in mind. Also time to introduce you to my good friend, the atttribute. Attributes are very helpful and there are many of them, some are only good for certain elements while others can be used for all. Attributes go inside the opening tag of an element after the element name and are set equal to some value: \<some-element some-attribute="some-value"\>. The attribute we need for images is src. Inside the quotes, we put the filename or url to the image. Make an <img> element after the Photos header with the src value set to: Jed.png
## Code:
\<!DOCTYPE html\>
\<html\>
  \<head\>
    \<title\>Dog Photos\</title\>
  \</head\>
  \<body\>
    \<h1\>Dog Photos\</h1\>
    \<p\>Dogs are great pets, here are some pictures of mine!\</p\>
    \<h2\>Photos\<h2\>
  \</body\>
\</html\>
## Answer:
\<!DOCTYPE html\>
\<html\>
  \<head\>
    \<title\>Dog Photos\</title\>
  \</head\>
  \<body\>
    \<h1\>Dog Photos\</h1\>
    \<p\>Dogs are great pets, here are some pictures of mine!\</p\>
    \<h2\>Photos\<h2\>
    \<img src="Jed.png"\>
  \</body\>
\</html\>
