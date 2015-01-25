ofxRing
=======

![Rings](ofxaddons_thumbnail.png)

Introduction
------------

This is a simple openFrameworks addon for drawing rings. The inner radius and the outer radius of the ring can vary independently.

Installation
------------

Clone this repository into your openFrameworks addon directory, for example:

    cd ~/openframeworks/addons/
    git clone https://github.com/elaye/ofxRing.git

Usage
-----

You can draw a ring directly like this:

    ofxDrawRing(float x, float y, float inner_radius, float outer_radius);

or

    ofxDrawRing(ofPoint position, float inner_radius, float outer_radius);

...or you can create a ring like this:

    ofxRing ring(float x, float y, float inner_radius, float outer_radius);

And then draw it:

    ring.draw();

You can set the properties of your ring with the following methods:

	void Ring::setPosition(float x, float y)
    void Ring::setInnerRadius(float r)
    void Ring::setOuterRadius(float r)
    void Ring::setResolution(int n)

Compatibility
-------------
This addon was tested with Linux and openFrameworks v0.8.3