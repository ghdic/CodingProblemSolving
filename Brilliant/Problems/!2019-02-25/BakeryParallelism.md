# BakeryParallelism
https://brilliant.org/daily-problems/parallel-bakery/


<p>Hans the baker makes many dozens of croissants in a single batch. Some of this work can be done faster if he has help: working together, Hans and one assistant can cut and roll croissants in half the time it would take Hans alone.</p>





<p></p><div class="image-caption center">
<div class="zoomable-image"><span></span><img src="https://ds055uzetaobb.cloudfront.net/brioche/uploads/Lf42l6W2gi-hans-and-one-helper.svg?width=300" srcset="https://ds055uzetaobb.cloudfront.net/brioche/uploads/Lf42l6W2gi-hans-and-one-helper.svg?width=300 1x,https://ds055uzetaobb.cloudfront.net/brioche/uploads/Lf42l6W2gi-hans-and-one-helper.svg?width=600 2x,https://ds055uzetaobb.cloudfront.net/brioche/uploads/Lf42l6W2gi-hans-and-one-helper.svg?width=900 3x" alt="" style="width:300px;max-width:100%;"></div>
</div><p></p>

<p>A computer scientist would say that Hans and his assistant were working in <em>parallel</em>.</p>

<p>Lots of assistants won’t make a batch of croissants cook any faster! A computer scientist would say that rolling croissants is <em>parallelizable</em>, but that the baking step is not parallelizable among multiple bakers.</p>

<p>Imagine a baking process that has four steps:</p>

<p></p><div class="image-caption center">
<div class="zoomable-image"><span></span><img src="https://ds055uzetaobb.cloudfront.net/brioche/uploads/SH8NKVo4jX-recipe.svg?width=300" srcset="https://ds055uzetaobb.cloudfront.net/brioche/uploads/SH8NKVo4jX-recipe.svg?width=300 1x,https://ds055uzetaobb.cloudfront.net/brioche/uploads/SH8NKVo4jX-recipe.svg?width=600 2x,https://ds055uzetaobb.cloudfront.net/brioche/uploads/SH8NKVo4jX-recipe.svg?width=900 3x" alt="" style="width:300px;max-width:100%;"></div>
</div><p></p>

<p>The first and third tasks, representing 30 minutes of work, can be split up among multiple bakers. The second and fourth tasks, representing 20 minutes of work, are not: more bakers won't help. </p>

<p>If Hans is working with one assistant, then the first and third steps get twice as fast: the first task takes 10 minutes and the third task takes 5 minutes, for a total of 15 minutes. The second and fourth steps stay the same and take 20 minutes, so the croissants will be ready in 35 minutes. This chart shows the time that each baking step takes for 1, 2, and 3 bakers: </p>

<p></p><div class="image-caption center">
<div class="zoomable-image"><span></span><img src="https://ds055uzetaobb.cloudfront.net/brioche/uploads/Spfpibk4Hf-croissant-gant-chart-daily-problems-meg.svg?width=500" srcset="https://ds055uzetaobb.cloudfront.net/brioche/uploads/Spfpibk4Hf-croissant-gant-chart-daily-problems-meg.svg?width=500 1x,https://ds055uzetaobb.cloudfront.net/brioche/uploads/Spfpibk4Hf-croissant-gant-chart-daily-problems-meg.svg?width=1000 2x,https://ds055uzetaobb.cloudfront.net/brioche/uploads/Spfpibk4Hf-croissant-gant-chart-daily-problems-meg.svg?width=1500 3x" alt="" style="width:500px;max-width:100%;"></div>
</div><p></p>

<p>As you can see, with three bakers, the total baking time is 30 minutes.</p>

<p>It's not <em>exactly</em> the case that the "prep" and "topping" steps can be split up perfectly among any number of bakers. With dozens of bakers cooperating, it might get crowded, and some bakers might need extra time to walk away and find space to work. However, we will often ignore this, just as we might ignore friction in a physics problem. </p>

<p>In that case, a simple formula tells us how much time it takes to perform a partially-parallelizable baking task with <span class="latexprocessor-inline latexprocessor-bef7e92d003faea67cf0be669d1bd7bfc28fa83e447e6dd8197ae1c63355437e"><svg xmlns:xlink="http://www.w3.org/1999/xlink" style="width: 1.444ex; height: 1.111ex; vertical-align: -0.222ex; margin-top: 1px; margin-right: 0px; margin-bottom: 1px; margin-left: 0px; " viewBox="0 -463.9033013280564 600 495.80660265611283"><defs id="MathJax_SVG_glyphs-46851128261311e3937340400601ade9ea3c92bc735949d58c9338629bebd4e0"><path id="MJMATHI-6E-46851128261311e3937340400601ade9ea3c92bc735949d58c9338629bebd4e0" stroke-width="0" d="M21 287Q22 293 24 303T36 341T56 388T89 425T135 442Q171 442 195 424T225 390T231 369Q231 367 232 367L243 378Q304 442 382 442Q436 442 469 415T503 336T465 179T427 52Q427 26 444 26Q450 26 453 27Q482 32 505 65T540 145Q542 153 560 153Q580 153 580 145Q580 144 576 130Q568 101 554 73T508 17T439 -10Q392 -10 371 17T350 73Q350 92 386 193T423 345Q423 404 379 404H374Q288 404 229 303L222 291L189 157Q156 26 151 16Q138 -11 108 -11Q95 -11 87 -5T76 7T74 17Q74 30 112 180T152 343Q153 348 153 366Q153 405 129 405Q91 405 66 305Q60 285 60 284Q58 278 41 278H27Q21 284 21 287Z"></path></defs><g stroke="black" fill="black" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><use xlink:href="#MJMATHI-6E-46851128261311e3937340400601ade9ea3c92bc735949d58c9338629bebd4e0"></use></g></svg></span> bakers. Say that <span class="latexprocessor-inline latexprocessor-5220707bcc6c973ee9df3f1b1089b126fb52d0bc063424a5729e57e706693e67"><svg xmlns:xlink="http://www.w3.org/1999/xlink" style="width: 1.222ex; height: 1.111ex; vertical-align: -0.222ex; margin-top: 1px; margin-right: 0px; margin-bottom: 1px; margin-left: 0px; " viewBox="0 -461.9033013280564 529 492.80660265611283"><defs id="MathJax_SVG_glyphs-41fb76b0261311e3937340400601ade9d897724fee1845a297ca1dfdb6429de6"><path id="MJMATHI-61-41fb76b0261311e3937340400601ade9d897724fee1845a297ca1dfdb6429de6" stroke-width="0" d="M33 157Q33 258 109 349T280 441Q331 441 370 392Q386 422 416 422Q429 422 439 414T449 394Q449 381 412 234T374 68Q374 43 381 35T402 26Q411 27 422 35Q443 55 463 131Q469 151 473 152Q475 153 483 153H487Q506 153 506 144Q506 138 501 117T481 63T449 13Q436 0 417 -8Q409 -10 393 -10Q359 -10 336 5T306 36L300 51Q299 52 296 50Q294 48 292 46Q233 -10 172 -10Q117 -10 75 30T33 157ZM351 328Q351 334 346 350T323 385T277 405Q242 405 210 374T160 293Q131 214 119 129Q119 126 119 118T118 106Q118 61 136 44T179 26Q217 26 254 59T298 110Q300 114 325 217T351 328Z"></path></defs><g stroke="black" fill="black" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><use xlink:href="#MJMATHI-61-41fb76b0261311e3937340400601ade9d897724fee1845a297ca1dfdb6429de6"></use></g></svg></span> is the amount of time the non-parallelizable work takes, and <span class="latexprocessor-inline latexprocessor-4e92c15aec5458acc79f9fc4ff17ace1109bfee735e8b1587bce5d86347ed81a"><svg xmlns:xlink="http://www.w3.org/1999/xlink" style="width: 1ex; height: 1.778ex; vertical-align: -0.222ex; margin-top: 1px; margin-right: 0px; margin-bottom: 1px; margin-left: 0px; " viewBox="0 -714.9033013280564 429 746.8066026561128"><defs id="MathJax_SVG_glyphs-4597348a261311e3937340400601ade90f90f01c82214651a386291ff17b69fc"><path id="MJMATHI-62-4597348a261311e3937340400601ade90f90f01c82214651a386291ff17b69fc" stroke-width="0" d="M73 647Q73 657 77 670T89 683Q90 683 161 688T234 694Q246 694 246 685T212 542Q204 508 195 472T180 418L176 399Q176 396 182 402Q231 442 283 442Q345 442 383 396T422 280Q422 169 343 79T173 -11Q123 -11 82 27T40 150V159Q40 180 48 217T97 414Q147 611 147 623T109 637Q104 637 101 637H96Q86 637 83 637T76 640T73 647ZM336 325V331Q336 405 275 405Q258 405 240 397T207 376T181 352T163 330L157 322L136 236Q114 150 114 114Q114 66 138 42Q154 26 178 26Q211 26 245 58Q270 81 285 114T318 219Q336 291 336 325Z"></path></defs><g stroke="black" fill="black" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><use xlink:href="#MJMATHI-62-4597348a261311e3937340400601ade90f90f01c82214651a386291ff17b69fc"></use></g></svg></span> is the amount of time the parallelizable work takes one baker. With our simplifying assumption, the time <span class="latexprocessor-inline latexprocessor-fb605cbde2733b2b0d8700d232cb2fc481acaf62079297409370016d0c1a3914"><svg xmlns:xlink="http://www.w3.org/1999/xlink" style="width: 0.889ex; height: 1.556ex; vertical-align: -0.222ex; margin-top: 1px; margin-right: 0px; margin-bottom: 1px; margin-left: 0px; " viewBox="0 -646.9033013280564 361 678.8066026561128"><defs id="MathJax_SVG_glyphs-b4e3dbe2278811e3bb5c40400601ade9fddfcb8e3f8a4e53b4934c95257d7f63"><path id="MJMATHI-74-b4e3dbe2278811e3bb5c40400601ade9fddfcb8e3f8a4e53b4934c95257d7f63" stroke-width="0" d="M26 385Q19 392 19 395Q19 399 22 411T27 425Q29 430 36 430T87 431H140L159 511Q162 522 166 540T173 566T179 586T187 603T197 615T211 624T229 626Q247 625 254 615T261 596Q261 589 252 549T232 470L222 433Q222 431 272 431H323Q330 424 330 420Q330 398 317 385H210L174 240Q135 80 135 68Q135 26 162 26Q197 26 230 60T283 144Q285 150 288 151T303 153H307Q322 153 322 145Q322 142 319 133Q314 117 301 95T267 48T216 6T155 -11Q125 -11 98 4T59 56Q57 64 57 83V101L92 241Q127 382 128 383Q128 385 77 385H26Z"></path></defs><g stroke="black" fill="black" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><use xlink:href="#MJMATHI-74-b4e3dbe2278811e3bb5c40400601ade9fddfcb8e3f8a4e53b4934c95257d7f63"></use></g></svg></span> that it takes to complete a task is <span class="latexprocessor-inline latexprocessor-64787a11bd991e5cabe59f5c15799ef3aa2d55e372d19f88fc0001873a676229"><svg xmlns:xlink="http://www.w3.org/1999/xlink" style="width: 9.778ex; height: 3ex; vertical-align: -1ex; margin-top: 1px; margin-right: 0px; margin-bottom: 1px; margin-left: 0px; " viewBox="0 -919.1123320645725 4230.264068711928 1292.634807985681"><defs><path id="MJMATHI-74-6eb30404356a11e9a5c902b7b6aa38869eed11f9722a41238d231415e1becc7d" stroke-width="0" d="M26 385Q19 392 19 395Q19 399 22 411T27 425Q29 430 36 430T87 431H140L159 511Q162 522 166 540T173 566T179 586T187 603T197 615T211 624T229 626Q247 625 254 615T261 596Q261 589 252 549T232 470L222 433Q222 431 272 431H323Q330 424 330 420Q330 398 317 385H210L174 240Q135 80 135 68Q135 26 162 26Q197 26 230 60T283 144Q285 150 288 151T303 153H307Q322 153 322 145Q322 142 319 133Q314 117 301 95T267 48T216 6T155 -11Q125 -11 98 4T59 56Q57 64 57 83V101L92 241Q127 382 128 383Q128 385 77 385H26Z"></path><path id="MJMAIN-3D-6eb30404356a11e9a5c902b7b6aa38869eed11f9722a41238d231415e1becc7d" stroke-width="0" d="M56 347Q56 360 70 367H707Q722 359 722 347Q722 336 708 328L390 327H72Q56 332 56 347ZM56 153Q56 168 72 173H708Q722 163 722 153Q722 140 707 133H70Q56 140 56 153Z"></path><path id="MJMATHI-61-6eb30404356a11e9a5c902b7b6aa38869eed11f9722a41238d231415e1becc7d" stroke-width="0" d="M33 157Q33 258 109 349T280 441Q331 441 370 392Q386 422 416 422Q429 422 439 414T449 394Q449 381 412 234T374 68Q374 43 381 35T402 26Q411 27 422 35Q443 55 463 131Q469 151 473 152Q475 153 483 153H487Q506 153 506 144Q506 138 501 117T481 63T449 13Q436 0 417 -8Q409 -10 393 -10Q359 -10 336 5T306 36L300 51Q299 52 296 50Q294 48 292 46Q233 -10 172 -10Q117 -10 75 30T33 157ZM351 328Q351 334 346 350T323 385T277 405Q242 405 210 374T160 293Q131 214 119 129Q119 126 119 118T118 106Q118 61 136 44T179 26Q217 26 254 59T298 110Q300 114 325 217T351 328Z"></path><path id="MJMAIN-2B-6eb30404356a11e9a5c902b7b6aa38869eed11f9722a41238d231415e1becc7d" stroke-width="0" d="M56 237T56 250T70 270H369V420L370 570Q380 583 389 583Q402 583 409 568V270H707Q722 262 722 250T707 230H409V-68Q401 -82 391 -82H389H387Q375 -82 369 -68V230H70Q56 237 56 250Z"></path><path id="MJMATHI-62-6eb30404356a11e9a5c902b7b6aa38869eed11f9722a41238d231415e1becc7d" stroke-width="0" d="M73 647Q73 657 77 670T89 683Q90 683 161 688T234 694Q246 694 246 685T212 542Q204 508 195 472T180 418L176 399Q176 396 182 402Q231 442 283 442Q345 442 383 396T422 280Q422 169 343 79T173 -11Q123 -11 82 27T40 150V159Q40 180 48 217T97 414Q147 611 147 623T109 637Q104 637 101 637H96Q86 637 83 637T76 640T73 647ZM336 325V331Q336 405 275 405Q258 405 240 397T207 376T181 352T163 330L157 322L136 236Q114 150 114 114Q114 66 138 42Q154 26 178 26Q211 26 245 58Q270 81 285 114T318 219Q336 291 336 325Z"></path><path id="MJMATHI-6E-6eb30404356a11e9a5c902b7b6aa38869eed11f9722a41238d231415e1becc7d" stroke-width="0" d="M21 287Q22 293 24 303T36 341T56 388T89 425T135 442Q171 442 195 424T225 390T231 369Q231 367 232 367L243 378Q304 442 382 442Q436 442 469 415T503 336T465 179T427 52Q427 26 444 26Q450 26 453 27Q482 32 505 65T540 145Q542 153 560 153Q580 153 580 145Q580 144 576 130Q568 101 554 73T508 17T439 -10Q392 -10 371 17T350 73Q350 92 386 193T423 345Q423 404 379 404H374Q288 404 229 303L222 291L189 157Q156 26 151 16Q138 -11 108 -11Q95 -11 87 -5T76 7T74 17Q74 30 112 180T152 343Q153 348 153 366Q153 405 129 405Q91 405 66 305Q60 285 60 284Q58 278 41 278H27Q21 284 21 287Z"></path></defs><g stroke="black" fill="black" stroke-width="0" transform="matrix(1 0 0 -1 0 0)"><use xlink:href="#MJMATHI-74-6eb30404356a11e9a5c902b7b6aa38869eed11f9722a41238d231415e1becc7d"></use><use xlink:href="#MJMAIN-3D-6eb30404356a11e9a5c902b7b6aa38869eed11f9722a41238d231415e1becc7d" x="638" y="0"></use><use xlink:href="#MJMATHI-61-6eb30404356a11e9a5c902b7b6aa38869eed11f9722a41238d231415e1becc7d" x="1694" y="0"></use><use xlink:href="#MJMAIN-2B-6eb30404356a11e9a5c902b7b6aa38869eed11f9722a41238d231415e1becc7d" x="2445" y="0"></use><g transform="translate(3566,0)"><rect stroke="none" width="544" height="60" x="0" y="220"></rect><use transform="scale(0.7071067811865476)" xlink:href="#MJMATHI-62-6eb30404356a11e9a5c902b7b6aa38869eed11f9722a41238d231415e1becc7d" x="170" y="576"></use><use transform="scale(0.7071067811865476)" xlink:href="#MJMATHI-6E-6eb30404356a11e9a5c902b7b6aa38869eed11f9722a41238d231415e1becc7d" x="84" y="-488"></use></g></g></svg></span>.</p>




<div class="b-readable-l">
<header class="b-vspace-m">
<h1>Today's Problem</h1>
</header>

<div class="solv-problem">
<div class="solv-content">




<div class="question-text latex">





<p>A batch of Hans’s special spanakopita croissants takes 50 minutes to make when Hans is joined by 3 assistants, and 40 minutes to prep when he is working together with 7 assistants.</p>

<p></p><div class="image-caption center">
<div class="zoomable-image"><span></span><img src="https://ds055uzetaobb.cloudfront.net/brioche/uploads/9gj4bXxLt9-hans-multitasking.svg?width=300" srcset="https://ds055uzetaobb.cloudfront.net/brioche/uploads/9gj4bXxLt9-hans-multitasking.svg?width=300 1x,https://ds055uzetaobb.cloudfront.net/brioche/uploads/9gj4bXxLt9-hans-multitasking.svg?width=600 2x,https://ds055uzetaobb.cloudfront.net/brioche/uploads/9gj4bXxLt9-hans-multitasking.svg?width=900 3x" alt="" style="width:300px;max-width:100%;"></div>
</div><p></p>

<p>How many minutes would it take Hans to make a batch if he was working alone?</p>


</div>


</div>
</div>
</div>


* 80 minutes
* 90 minutes
* 100 minutes
* 110 minutes

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





<p>A batch of Hans’s special spanakopita croissants takes 50 minutes to make when Hans is joined by 3 assistants, and 40 minutes to prep when he is working together with 7 assistants.</p>

<p></p><div class="image-caption center">
<div class="zoomable-image"><span></span><img src="https://ds055uzetaobb.cloudfront.net/brioche/uploads/9gj4bXxLt9-hans-multitasking.svg?width=300" srcset="https://ds055uzetaobb.cloudfront.net/brioche/uploads/9gj4bXxLt9-hans-multitasking.svg?width=300 1x,https://ds055uzetaobb.cloudfront.net/brioche/uploads/9gj4bXxLt9-hans-multitasking.svg?width=600 2x,https://ds055uzetaobb.cloudfront.net/brioche/uploads/9gj4bXxLt9-hans-multitasking.svg?width=900 3x" alt="" style="width:300px;max-width:100%;"></div>
</div><p></p>

<p>How many minutes would it take Hans to make a batch if he was working alone?</p>


</div>


</div>
</div>
</div>


* 80 minutes
* 90 minutes
* 100 minutes
* 110 minutes

===============================================

내가 고른 정답 : 

이유 : 

정답 : 

모범 답안 : 

