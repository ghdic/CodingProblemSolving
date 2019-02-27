# CanYouIsolateXFromY?
https://brilliant.org/daily-problems/min-cut-2/


<p>Today’s problem is a second, more complex example of the max-flow min-cut algorithm introduced in <a target="_blank" rel="nofollow" href="https://brilliant.org/daily-problems/min-cut/">yesterday’s daily problem</a>. Yesterday, our goal was to sever the fence pictured below using the fewest possible number of cuts. Additionally, to prove that our answer (five) is an optimal solution, we found five independent, horizontal paths across the fence, each of which must be cut <em>somewhere</em> to fully sever the fence. </p>

<p>


</p><div class="wistia-video center clearfix" data-controller="app/videos:wistiaController" data-width="400" data-video="u3jbdu5m78" data-controller-inited="true">

<template style="width: 400px; height: 225px;">

<div class="embed-wrapper" style="width:400px;max-width:100%;">
<script src="https://fast.wistia.com/embed/medias/u3jbdu5m78.jsonp" async=""></script>
<script src="https://fast.wistia.com/assets/external/E-v1.js" async=""></script>
<div class="wistia_embed wistia_async_u3jbdu5m78 videoFoam=true" style="height:100%;width:100%">&nbsp;</div>
</div>

</template>

<div class="embed-wrapper" style="width: 400px; max-width: 100%; height: 225px;">
<script src="https://fast.wistia.com/embed/medias/u3jbdu5m78.jsonp" async=""></script>
<script src="https://fast.wistia.com/assets/external/E-v1.js" async=""></script>
<div class="wistia_video_foam_dummy" data-source-container-id="wistia-u3jbdu5m78-1" style="border: 0px; display: block; height: 0px; margin: 0px; padding: 0px; position: static; visibility: hidden; width: auto;"></div><div class="wistia_embed wistia_async_u3jbdu5m78 videoFoam=true wistia_embed_initialized" style="height: 225px; width: 400px;" id="wistia-u3jbdu5m78-1"><div id="wistia_chrome_25" class="w-chrome" tabindex="-1" style="display: inline-block; height: 225px; margin: 0px; padding: 0px; position: relative; vertical-align: top; width: 400px; zoom: 1; outline: none; overflow: hidden; box-sizing: content-box;"><div id="wistia_grid_31_wrapper" style="display: block; width: 400px; height: 225px;"><div id="wistia_grid_31_above" style="height: 0px; font-size: 0px; line-height: 0px;"> </div><div id="wistia_grid_31_main" style="width: 400px; left: 0px; height: 225px; margin-top: 0px;"><div id="wistia_grid_31_behind"></div><div id="wistia_grid_31_center" style="width: 100%; height: 100%;"><div class="w-video-wrapper w-css-reset" style="height: 100%; position: absolute; top: 0px; width: 100%; opacity: 1; background-color: rgb(0, 0, 0);"><video id="wistia_simple_video_62" crossorigin="anonymous" poster="https://fast.wistia.com/assets/images/blank.gif" src="https://embedwistia-a.akamaihd.net/deliveries/fff25f38e296e519ab93023f0b9e5c31b52c9412/file.mp4" controlslist="nodownload" playsinline="" loop="" preload="auto" type="video/mp4" x-webkit-airplay="allow" style="background: transparent; display: block; height: 100%; max-height: none; max-width: none; position: static; visibility: visible; width: 100%; object-fit: contain;"><source src="https://embedwistia-a.akamaihd.net/deliveries/fff25f38e296e519ab93023f0b9e5c31b52c9412/file.mp4" type="video/mp4"></video></div><div class="w-ui-container" style="height: 100%; left: 0px; position: absolute; top: 0px; width: 100%; opacity: 1;"><style id="wistia_38_style" type="text/css" class="wistia_injected_style">
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset{font-size:14px;}
#wistia_chrome_25 #wistia_grid_31_wrapper div.w-css-reset{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper span.w-css-reset{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper ul.w-css-reset{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper li.w-css-reset{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper label.w-css-reset{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper button.w-css-reset{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper img.w-css-reset{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper a.w-css-reset{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper svg.w-css-reset{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper p.w-css-reset{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper a.w-css-reset{border:0;}
#wistia_chrome_25 #wistia_grid_31_wrapper p.w-css-reset{margin:1.4em 0;}
#wistia_chrome_25 #wistia_grid_31_wrapper a.w-css-reset{display:inline;}
#wistia_chrome_25 #wistia_grid_31_wrapper span.w-css-reset{display:inline;}
#wistia_chrome_25 #wistia_grid_31_wrapper svg.w-css-reset{display:inline;}
#wistia_chrome_25 #wistia_grid_31_wrapper ul.w-css-reset{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased;list-style-type:none}
#wistia_chrome_25 #wistia_grid_31_wrapper ol.w-css-reset{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased;list-style-type:none}
#wistia_chrome_25 #wistia_grid_31_wrapper li.w-css-reset{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased;list-style-type:none}
#wistia_chrome_25 #wistia_grid_31_wrapper ul:before.w-css-reset{display:none}
#wistia_chrome_25 #wistia_grid_31_wrapper ol:before.w-css-reset{display:none}
#wistia_chrome_25 #wistia_grid_31_wrapper li:before.w-css-reset{display:none}
#wistia_chrome_25 #wistia_grid_31_wrapper ul:after.w-css-reset{display:none}
#wistia_chrome_25 #wistia_grid_31_wrapper ol:after.w-css-reset{display:none}
#wistia_chrome_25 #wistia_grid_31_wrapper li:after.w-css-reset{display:none}
#wistia_chrome_25 #wistia_grid_31_wrapper label.w-css-reset{background-attachment:scroll;background-color:transparent;background-image:none;background-position:0 0;background-repeat:no-repeat;background-size:100% 100%;float:none;outline:none}
#wistia_chrome_25 #wistia_grid_31_wrapper button.w-css-reset{background-attachment:scroll;background-color:transparent;background-image:none;background-position:0 0;background-repeat:no-repeat;background-size:100% 100%;border:0;border-radius:0;outline:none;position:static}
#wistia_chrome_25 #wistia_grid_31_wrapper img.w-css-reset{border:0;display:inline-block;vertical-align:top;border-radius:0;outline:none;position:static}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree {font-size:14px;}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree div{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree span{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree ul{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree li{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree label{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree button{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree img{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree a{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree svg{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree p{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree a{border:0;}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree p{margin:1.4em 0;}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree a{display:inline;}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree span{display:inline;}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree svg{display:inline;}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree ul{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased;list-style-type:none}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree ol{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased;list-style-type:none}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree li{box-sizing:inherit;box-shadow:none;color:inherit;display:block;float:none;font:inherit;font-family:inherit;font-style:normal;font-weight:normal;font-size:inherit;letter-spacing:0;line-height:inherit;margin:0;max-height:none;max-width:none;min-height:none;min-width:none;padding:0;position:static;text-decoration:none;text-transform:none;text-shadow:none;transition:none;word-wrap:normal;-webkit-tap-highlight-color:rgba(0,0,0,0);-webkit-user-select:none;-webkit-font-smoothing:antialiased;list-style-type:none}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree ul:before{display:none}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree ol:before{display:none}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree li:before{display:none}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree ul:after{display:none}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree ol:after{display:none}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree li:after{display:none}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree label{background-attachment:scroll;background-color:transparent;background-image:none;background-position:0 0;background-repeat:no-repeat;background-size:100% 100%;float:none;outline:none}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree button{background-attachment:scroll;background-color:transparent;background-image:none;background-position:0 0;background-repeat:no-repeat;background-size:100% 100%;border:0;border-radius:0;outline:none;position:static}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-tree img{border:0;display:inline-block;vertical-align:top;border-radius:0;outline:none;position:static}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-max-width-none-important{max-width:none!important}
#wistia_chrome_25 #wistia_grid_31_wrapper .w-css-reset-button-important{border-radius:0!important;color:#fff!important;}
</style><div class="w-vulcan-v2 w-css-reset" id="w-vulcan-v2-30" role="region" aria-label="Video" tabindex="0" style="box-sizing: border-box; cursor: default; height: 100%; left: 0px; position: absolute; visibility: visible; top: 0px; width: 100%;"><div class="w-vulcan--background w-css-reset" style="height: 100%; left: 0px; position: absolute; top: 0px; width: 100%;"><div class="w-css-reset" data-handle="statusBar" style="pointer-events: auto;"></div><div class="w-css-reset" data-handle="thumbnail" style="pointer-events: auto;"><div><div class="w-css-reset" style="height: 100%; left: 0px; opacity: 1; position: absolute; top: 0px; width: 100%; display: block;"><img class="w-css-reset" srcset="https://embedwistia-a.akamaihd.net/deliveries/a83798f0da5846851d43d73836e296d3.jpg?image_crop_resized=640x360 320w, https://embedwistia-a.akamaihd.net/deliveries/a83798f0da5846851d43d73836e296d3.jpg?image_crop_resized=640x360 640w, https://embedwistia-a.akamaihd.net/deliveries/a83798f0da5846851d43d73836e296d3.jpg?image_crop_resized=960x540 960w, https://embedwistia-a.akamaihd.net/deliveries/a83798f0da5846851d43d73836e296d3.jpg?image_crop_resized=1280x720 1280w, https://embedwistia-a.akamaihd.net/deliveries/a83798f0da5846851d43d73836e296d3.jpg?image_crop_resized=1280x720 1920w, https://embedwistia-a.akamaihd.net/deliveries/a83798f0da5846851d43d73836e296d3.jpg?image_crop_resized=1280x720 3840w" src="https://embedwistia-a.akamaihd.net/deliveries/a83798f0da5846851d43d73836e296d3.jpg?image_crop_resized=640x360" alt="Video Thumbnail" style="border-width: 0px; border-style: solid; border-color: rgb(0, 0, 0); box-sizing: content-box; height: 225px; left: 0px; position: absolute; top: 0px; width: 400px; clip: auto; display: block;"></div></div></div></div><div class="w-vulcan-overlays-table w-css-reset" style="display: table; pointer-events: none; position: absolute; width: 100%;"><div class="w-vulcan-overlays--left w-css-reset" style="display: table-cell; vertical-align: top; position: relative; width: 0px;"><div class="w-css-reset" style="height: 225px;"></div></div><div class="w-vulcan-overlays--center w-css-reset" style="display: table-cell; vertical-align: top; position: relative; width: 100%;"><div class="w-css-reset" style="height: 225px;"><div class="w-css-reset" data-handle="bigPlayButton" style="pointer-events: auto;"><div class="w-bpb-wrapper w-css-reset w-css-reset-tree" style="display: block; left: 50%; position: absolute; top: 50%; transform: translate(-50%, -50%);"><button class="w-big-play-button w-css-reset-button-important w-vulcan-v2-button" aria-label="Play DP Don't Break That" style="cursor: pointer; height: 50px; background: rgba(61, 153, 246, 0.8); box-shadow: none; width: 78.125px;"><svg x="0px" y="0px" viewBox="0 0 125 80" enable-background="new 0 0 125 80" alt="" style="fill: rgb(255, 255, 255); height: 100%; left: 0px; stroke-width: 0px; top: 0px; width: 100%;"><rect fill-rule="evenodd" clip-rule="evenodd" fill="none" width="125" height="80"></rect><polygon fill-rule="evenodd" clip-rule="evenodd" fill="#FFFFFF" points="53,22 53,58 79,40"></polygon></svg></button></div></div><div class="w-css-reset" data-handle="clickForSoundButton" style="pointer-events: auto;"><div class="w-css-reset w-css-reset-tree" style="display: none; height: 100%; left: 0px; pointer-events: none; position: absolute; top: 0px; width: 100%;"><button class="w-vulcan-v2-button" style="background: rgba(0, 0, 0, 0.4); border: 2px solid transparent; border-radius: 20.25px; cursor: pointer; height: 26.25px; line-height: 26.25px; outline: none; padding-right: 7.5px; pointer-events: auto; position: absolute; right: 9.25px; text-align: left; top: 9.25px;"><svg viewBox="0 0 237 237" style="height: 24px; margin-top: 0.375px; vertical-align: top; width: 26.25px;"><style>
@keyframes VOLUME_SMALL_WAVE_FLASH {
0% { opacity: 0; }
33% { opacity: 1; }
66% { opacity: 1; }
100% { opacity: 0; }
}

@keyframes VOLUME_LARGE_WAVE_FLASH {
0% { opacity: 0; }
33% { opacity: 1; }
66% { opacity: 1; }
100% { opacity: 0; }
}

.volume__small-wave {
animation: VOLUME_SMALL_WAVE_FLASH 2s infinite;
opacity: 0;
}

.volume__large-wave {
animation: VOLUME_LARGE_WAVE_FLASH 2s infinite .3s;
opacity: 0;
}
</style><polygon fill="white" points="88 107 65 107 65 131 89 131 112 154 112 84"></polygon><g fill="none" stroke="white" stroke-width="10" stroke-linecap="round"><path class="volume__small-wave" d="M 142 86 C 151 107 151 130 142 151"></path><path class="volume__large-wave" d="M 165 74 C 178 97 178 140 165 163"></path></g></svg><div style="color: white; display: inline-block; font-family: WistiaPlayerOverpass, Helvetica, sans-serif; font-size: 9.75px; margin-left: -3px; margin-top: -0.5625px; vertical-align: top; white-space: nowrap; width: 36%;">Click for sound</div></button></div></div><div class="w-css-reset" data-handle="loadingIndicator" style="pointer-events: auto;"></div><div class="w-css-reset" data-handle="playPauseNotifier" style="pointer-events: auto;"></div></div></div><div class="w-vulcan-overlays--right w-css-reset" style="display: table-cell; vertical-align: top; position: relative; width: 0px;"><div class="w-css-reset" style="height: 225px;"></div></div></div><div class="w-bottom-bar w-css-reset" style="bottom: 0px; border-collapse: collapse; display: none; height: 0px; left: 0px; opacity: 0; pointer-events: none; position: absolute; table-layout: auto; transition: opacity 0s ease 0s; width: 100%;"><div class="w-bottom-bar-upper w-css-reset" style="display: none;"><div class="w-css-reset" data-handle="upperPlaybar" style="height: 100%; pointer-events: auto;"><div class="w-playbar-wrapper w-css-reset w-css-reset-tree" role="slider" aria-label="Playbar" aria-orientation="horizontal" aria-valuenow="0" aria-valuemin="0" aria-valuemax="14.982" aria-valuetext="0:00" tabindex="0" style="cursor: pointer; height: 100%; outline: none; position: relative;"><div style="display: block; height: 100%; overflow: hidden; pointer-events: none; position: relative; width: 400px;"><canvas width="400" height="10" style="height: 10px; left: 0px; pointer-events: none; position: absolute; top: 0px; width: 400px;"></canvas></div><div class="w-playbar__hoverMarker" style="background: linear-gradient(to right, rgba(255, 255, 255, 0) 0%, rgba(255, 255, 255, 0.12) 100%); display: none; height: 100%; left: -36px; pointer-events: none; position: absolute; top: 0px; width: 36px;"></div><div class="w-playbar__focus-border" style="border: 2px solid rgb(255, 255, 255); display: none; height: 100%; left: 0px; pointer-events: none; position: absolute; top: 0px; width: 100%;"></div></div></div></div><div class="w-bottom-bar-lower w-css-reset"><div class="w-bottom-bar-left w-css-reset" style="display: table-cell; vertical-align: top; position: relative; width: 0px;"><div class="w-bottom-bar-left-inner w-css-reset" style="height: 21px; position: relative; white-space: nowrap;"><div class="w-css-reset" data-handle="smallPlayButton" style="display: inline-block; vertical-align: top; pointer-events: auto;"><div class="w-vulcan-button-wrapper w-css-reset" style="display: inline-block; height: 21px; position: relative; vertical-align: top; width: 31px;"><button class="w-vulcan-v2-button w-css-reset w-css-reset-tree w-css-reset-button-important" aria-label="Play" title="Play" style="background: rgba(61, 153, 246, 0.95); box-shadow: none; cursor: pointer; height: 100%; position: relative; width: 100%; transition: opacity 400ms ease 0s; opacity: 1;"><div class="w-vulcan-icon-wrapper" data-handle="smallPlayButton" style="box-sizing: border-box; height: 100%;"><div style="height: 100%; width: 100%;"><div style="display: none; height: 100%; width: 100%;"><svg x="0px" y="0px" viewBox="0 0 51.556 34" enable-background="new 0 0 51.556 34" class="w-css-reset w-css-reset-tree" style="fill: rgb(255, 255, 255); height: 100%; left: 0px; stroke-width: 0px; top: 0px; width: 100%;"><g><rect x="20" y="11.3" width="3.5" height="12"></rect><rect x="26.5" y="11.3" width="3.5" height="12"></rect></g></svg></div><div style="display: block; height: 100%; width: 100%;"><svg x="0px" y="0px" viewBox="0 0 51.556 34" enable-background="new 0 0 51.556 34" class="w-css-reset w-css-reset-tree" style="fill: rgb(255, 255, 255); height: 100%; left: 0px; stroke-width: 0px; top: 0px; width: 100%;"><polygon points="31.555999999999997,16.5 20,24 20,9"></polygon></svg></div></div></div></button></div></div></div></div><div class="w-bottom-bar-middle w-css-reset" style="display: table-cell; vertical-align: top; position: relative; width: 100%;"><div class="w-bottom-bar-middle-inner w-css-reset" style="height: 21px; position: relative; white-space: nowrap;"><div class="w-css-reset" data-handle="lowerPlaybar" style="height: 100%; pointer-events: auto;"><div class="w-playbar-wrapper w-css-reset w-css-reset-tree" role="slider" aria-label="Playbar" aria-orientation="horizontal" aria-valuenow="0" aria-valuemin="0" aria-valuemax="14.982" aria-valuetext="0:00" tabindex="0" style="cursor: pointer; height: 100%; outline: none; position: relative;"><div style="display: block; height: 100%; overflow: hidden; pointer-events: none; position: relative; width: 319px;"><canvas width="319" height="21" style="height: 21px; left: 0px; pointer-events: none; position: absolute; top: 0px; width: 319px;"></canvas></div><div class="w-playbar__hoverMarker" style="background: linear-gradient(to right, rgba(255, 255, 255, 0) 0%, rgba(255, 255, 255, 0.12) 100%); display: none; height: 100%; left: -36px; pointer-events: none; position: absolute; top: 0px; width: 36px;"></div><div class="w-playbar__focus-border" style="border: 2px solid rgb(255, 255, 255); display: none; height: 100%; left: 0px; pointer-events: none; position: absolute; top: 0px; width: 100%;"></div></div></div></div></div><div class="w-bottom-bar-right w-css-reset" style="display: table-cell; vertical-align: top; position: relative; width: 0px;"><div class="w-bottom-bar-right-inner w-css-reset" style="height: 21px; position: relative; white-space: nowrap;"><div class="w-css-reset" data-handle="volumeButton" style="display: inline-block; vertical-align: top; pointer-events: auto;"><div class="w-vulcan-button-wrapper w-css-reset" style="display: inline-block; height: 21px; position: relative; vertical-align: top; width: 25px;"><button class="w-vulcan-v2-button w-css-reset w-css-reset-tree w-css-reset-button-important" aria-label="Mute" title="Mute" style="background: rgba(61, 153, 246, 0.95); box-shadow: none; cursor: pointer; height: 100%; position: relative; width: 100%; transition: opacity 400ms ease 0s; opacity: 1;"><div class="w-vulcan-icon-wrapper" data-handle="volumeButton" style="box-sizing: border-box; height: 100%;"><svg x="0px" y="0px" viewBox="0 0 40 34" enable-background="new 0 0 40 34" style="fill: rgb(255, 255, 255); height: 100%; left: 0px; stroke-width: 0px; top: 0px; width: 100%;"><g style="transform: translateX(1.25px); transition: transform 100ms ease 0s;"><g><path d="M13.8,14.2c-0.5,0.5-1.4,0.8-2,0.8h-1.6C9.5,15,9,15.5,9,16.2v1.6c0,0.7,0.5,1.2,1.2,1.2h1.6c0.7,0,1.6,0.4,2,0.8l2.3,2.3c0.5,0.5,0.8,0.3,0.8-0.4v-9.6c0-0.7-0.4-0.8-0.8-0.4L13.8,14.2z"></path></g><g><path fill="none" stroke="#ffffff" stroke-line-cap="round" stroke-miterlimit="10" stroke-width="2" d="M22,11.7c0,0,1.1,2.5,1.1,5s-1.1,5-1.1,5" style="opacity: 1; transition: opacity 100ms ease 0s;"></path><path fill="none" stroke="#ffffff" stroke-line-cap="round" stroke-miterlimit="10" stroke-width="2" d="M25.8,9.2c0,0,1.7,3.8,1.7,7.5c0,3.7-1.7,7.5-1.7,7.5" style="opacity: 1; transition: opacity 100ms ease 0s;"></path></g><g style="opacity: 0; transition: opacity 100ms ease 0s;"><line fill="none" stroke="#ffffff" stroke-line-cap="round" stroke-miterlimit="10" stroke-width="1.8102" x1="19.2" y1="15" x2="23.2" y2="19"></line><line fill="none" stroke="#ffffff" stroke-line-cap="round" stroke-miterlimit="10" stroke-width="1.8102" x1="19.2" y1="19" x2="23.2" y2="15"></line></g></g></svg></div></button></div></div><div class="w-css-reset" data-handle="fullscreenButton" style="display: inline-block; vertical-align: top; pointer-events: auto;"><div class="w-vulcan-button-wrapper w-css-reset" style="display: inline-block; height: 21px; position: relative; vertical-align: top; width: 25px;"><button class="w-vulcan-v2-button w-css-reset w-css-reset-tree w-css-reset-button-important" aria-label="Fullscreen" title="Fullscreen" style="background: rgba(61, 153, 246, 0.95); box-shadow: none; cursor: pointer; height: 100%; position: relative; width: 100%; transition: opacity 400ms ease 0s; opacity: 1;"><div class="w-vulcan-icon-wrapper" data-handle="fullscreenButton" style="box-sizing: border-box; height: 100%;"><svg x="0px" y="0px" viewBox="0 0 40 34" enable-background="new 0 0 40 34" style="fill: rgb(255, 255, 255); height: 100%; left: 0px; stroke-width: 0px; top: 0px; width: 100%;"><g><g><polyline fill="none" stroke="#ffffff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" stroke-miterlimit="10" points="31.4,12.6 31.4,8.7 25.8,8.7"></polyline><polyline fill="none" stroke="#ffffff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" stroke-miterlimit="10" points="14.7,8.7 9.1,8.7 9.1,12.6"></polyline><polyline fill="none" stroke="#ffffff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" stroke-miterlimit="10" points="25.8,24.8 31.4,24.8 31.4,20.9"></polyline><polyline fill="none" stroke="#ffffff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" stroke-miterlimit="10" points="9.1,20.9 9.1,24.8 14.7,24.8"></polyline></g><rect x="13.7" y="12.3" fill="none" stroke="#ffffff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" stroke-miterlimit="10" enable-background="new" width="13.3" height="8.9"></rect></g></svg></div></button></div></div></div></div></div></div><div class="w-foreground w-css-reset" style="height: 100%; left: 0px; pointer-events: none; position: absolute; top: 0px; width: 100%;"><div class="w-css-reset" data-handle="contextMenu" style="pointer-events: auto;"></div><div class="w-css-reset" data-handle="loadingHourglass" style="pointer-events: auto;"></div></div><div class="w-focus-border" style="border: 2px solid rgb(255, 255, 255); box-sizing: border-box; display: none; height: 100%; left: 0px; pointer-events: none; position: absolute; top: 0px; width: 100%;"></div></div></div></div><div id="wistia_grid_31_front"></div><div id="wistia_grid_31_top_inside"><div id="wistia_grid_31_top" style="height: 0px; font-size: 0px; line-height: 0px;"> </div></div><div id="wistia_grid_31_bottom_inside"><div id="wistia_grid_31_bottom" style="height: 0px; font-size: 0px; line-height: 0px;"> </div></div><div id="wistia_grid_31_left_inside"><div id="wistia_grid_31_left" style="height: 0px; font-size: 0px; line-height: 0px;"> </div></div><div id="wistia_grid_31_right_inside"><div id="wistia_grid_31_right" style="height: 0px; font-size: 0px; line-height: 0px;"> </div></div></div><div id="wistia_grid_31_below" style="height: 0px; font-size: 0px; line-height: 0px;"> </div><style id="wistia_32_style" type="text/css" class="wistia_injected_style">#wistia_grid_31_wrapper{-moz-box-sizing:content-box;-webkit-box-sizing:content-box;box-sizing:content-box;font-family:Arial,sans-serif;font-size:14px;height:100%;position:relative;text-align:left;width:100%;}
#wistia_grid_31_wrapper *{-moz-box-sizing:content-box;-webkit-box-sizing:content-box;box-sizing:content-box;}
#wistia_grid_31_above{position:relative;}
#wistia_grid_31_main{display:block;height:100%;position:relative;}
#wistia_grid_31_behind{height:100%;left:0;position:absolute;top:0;width:100%;}
#wistia_grid_31_center{height:100%;overflow:hidden;position:relative;width:100%;}
#wistia_grid_31_front{display:none;height:100%;left:0;position:absolute;top:0;width:100%;}
#wistia_grid_31_top_inside{position:absolute;left:0;top:0;width:100%;}
#wistia_grid_31_top{width:100%;position:absolute;bottom:0;left:0;}
#wistia_grid_31_bottom_inside{position:absolute;left:0;bottom:0;width:100%;}
#wistia_grid_31_bottom{width:100%;position:absolute;top:0;left:0;}
#wistia_grid_31_left_inside{height:100%;position:absolute;left:0;top:0;}
#wistia_grid_31_left{height:100%;position:absolute;right:0;top:0;}
#wistia_grid_31_right_inside{height:100%;right:0;position:absolute;top:0;}
#wistia_grid_31_right{height:100%;left:0;position:absolute;top:0;}
#wistia_grid_31_below{position:relative;}</style></div></div></div>
</div></div>



<p></p>








<p>However, yesterday we didn’t go into the details for how we knew <strong><em>where to cut</em></strong> on each of the horizontal paths.  With a small graph, you can try to do this step intuitively. However, if you have a much larger graph or if you’re trying to write a computer program to find the solution, you’ll want a completely reliable algorithm, not just intuition.</p>

<p>To start exploring this part of the process, we’ll begin by physically modeling the problem with water flowing through a network. Then we’ll show how to use the physical model to find the most efficient way to cut the system apart. What matters today isn’t the implementation (physical or computational) but rather understanding how to go from identifying the max-flow of a network to finding precisely what minimal set of edges in a network can be cut to sever the network.</p>

<p>Although the example below may seem like a crazy plumbing hookup, just remember that water flowing through pipes is a model for any kind of flow network—from the flow of data through a digital network to the flow of traffic on a network of roads.</p>

<p></p><div class="image-caption center">
<div class="zoomable-image"><span></span><img src="https://ds055uzetaobb.cloudfront.net/brioche/uploads/HgPzRW9w17-group52.svg?width=350" srcset="https://ds055uzetaobb.cloudfront.net/brioche/uploads/HgPzRW9w17-group52.svg?width=350 1x,https://ds055uzetaobb.cloudfront.net/brioche/uploads/HgPzRW9w17-group52.svg?width=700 2x,https://ds055uzetaobb.cloudfront.net/brioche/uploads/HgPzRW9w17-group52.svg?width=1050 3x" alt="" style="width:350px;max-width:100%;"></div>
</div><p></p>

<blockquote>
<p><strong>The Max-Flow Perspective:</strong> Given that the individual capacity of each green tube in the system above is 1 cup per second, how much water per second can be pushed through the entire network from the hydrant to the bucket?</p>

<p><strong>The Min-Cut Perspective:</strong> What is the least number of tubes that we could cut in order to entirely sever the flow of water from the hydrant to the bucket?</p>
</blockquote>

<p>In this model, water from the hydrant is constrained by the flow capacity of the green tubes. Assume that, under the pressure of the hydrant, only one cup of water per second can flow through any segment of the green tube. But don’t worry about congestion at the pipe intersections—assume that if several one-cup-per-second streams of water can come in and leave via independent tubes, the intersection of those flows at a joint doesn’t affect the flow of any stream.  </p>

<blockquote>
<p><strong>Using a Physical Calculator</strong></p>

<p>To find the <em>min-cut</em> for a water network (if the system were real), first, turn on the hydrant and wait till the flow into the bucket steadies. Then repeat these steps until the system is fully severed:</p>

<p>Step 1:  Find a tube segment that water is flowing through at full capacity.  Somewhere along the path that any stream of water takes, there will be at least one such tube (otherwise, the system isn't really being used at full capacity). </p>

<p>Step 2: Once you've found such a tube segment, test squeezing it shut. If squeezing it shut reduces the capacity of the system because the water can't find another way to get through, then cut it. If squeezing it shut doesn’t reduce the capacity of the system, leave it squeezed shut (but don’t cut it). </p>

<p>When you’re following these instructions, with each cut, the capacity of the system will decrease until at last it decreases to 0.</p>
</blockquote>

<p>The water-pushing technique explained above will always allow you to identify a set of segments to cut that fully severs the network, separating the 'source' (the hydrant) on one side and the 'sink' (the bucket) on the other. However, if you don’t want to build a physical plumbing network, you can use the <a href="/wiki/ford-fulkerson-algorithm/" class="wiki_link" title="Ford-Fulkerson algorithm" target="_blank">Ford-Fulkerson algorithm</a> or the <a href="/wiki/edmonds-karp-algorithm/" class="wiki_link" title="Edmonds-Karp" target="_blank">Edmonds-Karp</a> variant to computationally find a maximum-flow solution and implement the ‘pinching’ tests.</p>




<div class="b-readable-l">
<header class="b-vspace-m">
<h1>Today's Problem</h1>
</header>

<div class="solv-problem">
<div class="solv-content">




<div class="question-text latex">





<p></p><div class="image-caption center">
<div class="zoomable-image"><span></span><img src="https://ds055uzetaobb.cloudfront.net/brioche/uploads/S28UcONufQ-group-21-1.svg?width=400" srcset="https://ds055uzetaobb.cloudfront.net/brioche/uploads/S28UcONufQ-group-21-1.svg?width=400 1x,https://ds055uzetaobb.cloudfront.net/brioche/uploads/S28UcONufQ-group-21-1.svg?width=800 2x,https://ds055uzetaobb.cloudfront.net/brioche/uploads/S28UcONufQ-group-21-1.svg?width=1200 3x" alt="" style="width:400px;max-width:100%;"></div>
</div><p></p>

<p>What is the <strong>minimum number of edges</strong> that must be removed from this network graph in order to isolate X from Y so that there’s no path along edges between them?</p>


</div>


</div>
</div>
</div>


* 4
* 5
* 6
* 7

===============================================



# 내 멋대로 발직역
# 제목

<div class="b-readable-l">
<header class="b-vspace-m">
<h1>Today's Problem</h1>
</header>

<div class="solv-problem">
<div class="solv-content">




<div class="question-text latex">





<p></p><div class="image-caption center">
<div class="zoomable-image"><span></span><img src="https://ds055uzetaobb.cloudfront.net/brioche/uploads/S28UcONufQ-group-21-1.svg?width=400" srcset="https://ds055uzetaobb.cloudfront.net/brioche/uploads/S28UcONufQ-group-21-1.svg?width=400 1x,https://ds055uzetaobb.cloudfront.net/brioche/uploads/S28UcONufQ-group-21-1.svg?width=800 2x,https://ds055uzetaobb.cloudfront.net/brioche/uploads/S28UcONufQ-group-21-1.svg?width=1200 3x" alt="" style="width:400px;max-width:100%;"></div>
</div><p></p>

<p>What is the <strong>minimum number of edges</strong> that must be removed from this network graph in order to isolate X from Y so that there’s no path along edges between them?</p>


</div>


</div>
</div>
</div>


* 4
* 5
* 6
* 7

===============================================

내가 고른 정답 : 

이유 : 

정답 : 

모범 답안 : 

