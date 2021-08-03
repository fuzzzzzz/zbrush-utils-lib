#include "stdafx.h"
#include <cstring>
#include <string>

// #define NUMBER_OF_STRING 255
// #define MAX_STRING_SIZE 255

const char * switches[] =
{   
    "tool:geometry:smt", "tool:subtool:polygrp","tool:subtool:geometry", "tool:subtool:color", "tool:subtool:farthest",
    "tool:subtool:outer", "tool:subtool:inner", "tool:subtool:double", "tool:subtool:tcorner",
    "tool:subtool:tborder", "tool:geometry:suv", "tool:geometry:s.dynamic",
    "tool:geometry:s.bevel", "tool:geometry:s.chamfer", "tool:geometry:s.constant", "tool:geometry:crisp",
    "tool:geometry:triangle", "tool:geometry:p.double", "tool:geometry:p.ignore groups", "tool:geometry:p.regrouppanels",
    "tool:geometry:p.regrouploops", "tool:geometry:d.partial", "tool:geometry:d.groups", "tool:geometry:b.propwidth",
    "tool:geometry:dynamesh", "tool:geometry:groups", "tool:geometry:d.polish", "tool:geometry:project", "tool:geometry:tessimate", "tool:geometry:decimate", "tool:geometry:Legacy (2018)",
    "tool:geometry:freezeborder", "tool:geometry:freezegroups", "tool:geometry:keepgroups", "tool:geometry:keepcrease",
    "tool:geometry:detectedges", "tool:geometry:half", "tool:geometry:same", "tool:geometry:double", "tool:geometry:adapt",
    "tool:geometry:use polypaint", "tool:masking:border", "tool:masking:groups", "tool:masking:crease",
    "tool:polypaint:colorize", "tool:polypaint:grd", "tool:display properties:double", "tool:import:mrg", "tool:import:add",

    "tool:export:qud","tool:export:tri","tool:export:txr","tool:export:flp","tool:export:mrg","tool:export:grp",
    "tool:export:smooth normals",
    "alpha:ep", "alpha:modify:max", "alpha:modify:aa", "alpha:modify:surface", "alpha:make 3d:dbls", "alpha:transfer:cc",    
    "brush:curve:accucurve", "brush:curve:curve by pen", "brush:depth:depth mask", "brush:depth:infinite depth",
    "brush:sample:buildup", "brush:sample:fast samples", "brush:sample:constsamples", "brush:sample:onsurface",
    "brush:sample:spotlight projection", "brush:modifiers:constanttilt", "brush:sculptrispro:enable", "brush:sculptrispro:use global",
    "brush:sculptrispro:adaptive size", "brush:sculptrispro:combined",
    "brush:auto masking:auto mask mesh insert", "brush:auto masking:auto mask fibermesh", "brush:auto masking:directional",
    "brush:auto masking:backfacemask", "brush:auto masking:colormask", "brush:auto masking:topological",
    "brush:tablet pressure:use global settings", "brush:clip brush modifiers:bradius", "brush:clip brush modifiers:polygroup",
    "color:gradient", "color:alternate", "document:wsize", "document:pro", "draw:mrgb", "draw:rgb", "draw:m", "draw:a", "draw:zadd", "draw:zsub", "draw:perspective", "draw:align to object",
    "draw:auto adjust distance", "draw:camera", "draw:horizontal", "draw:vertical", "draw:18", "draw:24",
    "draw:28", "draw:35", "draw:50", "draw:85", "draw:lock camera", "draw:floor", "draw:snap", "draw:front",
    "draw:snaptosbox", "draw:channels:infront", "draw:channels:behind", "draw:channels:r", "draw:channels:g", "draw:channels:b",
    "edit:tool:restore placement",
    "file:undohistory", 
    "layer:w", "layer:auto select",    
    "transform:draw pointer", "transform:move", "transform:rotate", "transform:scale", "transform:gizmo 3d", "transform:editspotlight", 
    "transform:edit", "transform:rot xyz", "transform:rot x", "transform:rot y", "transform:rot z", "transform:lsym",
    "transform:vcenter", "transform:xpose", "transform:local transform", "transform:quick 3d edit",
    "transform:pf", "transform:pd", "transform:da", "transform:dots", "transform:solo", "transform:pointselect",
    "transform:activate", "transform:ghost transparency", "transform:activate symmetry", "transform:>x<", "transform:>y<",
    "transform:>y<", "transform:>m<", "transform:(r)", "transform:modifiers:xyz", "transform:modifiers:x",
    "transform:modifiers:y",  "transform:modifiers:z",  "transform:s",  "transform:a.i",

    "zscript:show actions", "zscript:&notes","zscript:skip notes", "zscript:skip audio", "zscript:cmd", "zscript:rec", "zscript:text", "zscript:run",
    "zscript:minimal stroke", "zscript:minimal update", "marker:on/off", "marker:show", "marker:tool", "marker:draw", "marker:position", "marker:normal",
    "marker:color", "marker:material", "marker:texture", "movie:doc", "movie:window", "movie:large", "movie:medium", "movie:small", "movie:timeline:show",
    "movie:timeline:exportname", "movie:timeline:auto",
    "render:freeze", "render:render","render:best", "render:preview", "render:fast", "render:flat", "render:render booleans:live boolean",
    "render:render properties:smoothnormals", "render:render properties:draw micromesh", "render:render properties:shadows", "render:render properties:aocclusion",
    "render:render properties:flat shadows", "render:render properties:sss", "render:render properties:transparent", "render:render properties:waxpreview",
    "render:render properties:view blur", "render:render properties:fibers", "render:render properties:hdgeometry", "render:render properties:fog",
    "render:render properties:depth cue", "render:render properties:softz", "render:render properties:softrgb", "render:render properties:flatten"
   
    // ~160 items
    // light, movie, marker, material, picker, preferences, render, stencil, stroke, texture, transform, zscript,  

};




