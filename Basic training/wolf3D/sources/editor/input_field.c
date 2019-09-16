/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:03:04 by djast             #+#    #+#             */
/*   Updated: 2019/09/15 16:27:06 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void handle_input()
{
// 	int quit;
// 	int render_text;
// 	SDL_Event e;

// 	quit = 0;
// 	while( !quit )
// 	{
// 		render_text = 0;
// 		while( SDL_PollEvent( &e ) != 0 )
// 		{
// 			if( e.type == SDL_KEYDOWN )
// 			{
// 				//Handle backspace
// 				if( e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 )
// 				{
// 					//lop off character
// 					inputText.pop_back();
// 				}
// 				renderText = true;
// 				}
// 			}
// 			else if( e.type == SDL_TEXTINPUT )
// 			{
// 				//Not copy or pasting
// 				if( !( SDL_GetModState() & KMOD_CTRL && ( e.text.text[ 0 ] == 'c' || e.text.text[ 0 ] == 'C' || e.text.text[ 0 ] == 'v' || e.text.text[ 0 ] == 'V' ) ) )
// 				{
// 					//Append character
// 					inputText += e.text.text;
// 					renderText = true;
// 				}
// 			}
// 		}
// 		if( renderText )
// 		{
// 			//Text is not empty
// 			if( inputText != "" )
// 			{
// 				//Render new text
// 				gInputTextTexture.loadFromRenderedText( inputText.c_str(), textColor );
// 			}
// 			//Text is empty
// 			else
// 			{
// 				//Render space texture
// 				gInputTextTexture.loadFromRenderedText( " ", textColor );
// 			}
// 		}
// 		 SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
// 		SDL_RenderClear( gRenderer );

// 		//Render text textures
// 		gPromptTextTexture.render( ( SCREEN_WIDTH - gPromptTextTexture.getWidth() ) / 2, 0 );
// 		gInputTextTexture.render( ( SCREEN_WIDTH - gInputTextTexture.getWidth() ) / 2, gPromptTextTexture.getHeight() );

// 		//Update screen
// 		SDL_RenderPresent( gRenderer );
// 		}
}

void put_input_field(t_sdl *sdl, t_input_field *field)
{
	(void) sdl;
	(void) field;
	//gInputTextTexture.loadFromRenderedText( inputText.c_str(), textColor );

	//Enable text input
	SDL_StartTextInput();
	handle_input();
	SDL_StopTextInput();
}