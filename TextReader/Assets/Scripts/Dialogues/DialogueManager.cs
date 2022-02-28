using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DialogueManager : MonoBehaviour
{
    public Text nameText;
    public Text dialogueText;

    [Range(.01f, .1f)]
    public float textSpeed;

    public Animator animator;

    private Queue<string> sentences;

    // Start is called before the first frame update
    void Start()
    {
        sentences = new Queue<string>();
    }

    public void StartDialogue (Dialogue dialogue)
    {
        animator.SetBool("IsOpen", true);

        nameText.text = dialogue.name;

        sentences.Clear();

        foreach(string sentence in dialogue.sentences)
        {
            sentences.Enqueue(sentence);
        }

        DisplayNextSentence();
    }

    public void DisplayNextSentence()
    {
        if(sentences.Count == 0)
        {
            EndDialogue();
            return;
        }
        string sentence = sentences.Dequeue();
        StopAllCoroutines();
        StartCoroutine(TypeSentence(sentence));
    }

    IEnumerator TypeSentence(string sentence)
    {
        dialogueText.text = "";
        foreach(char letter in sentence.ToCharArray())
        {
            dialogueText.text += letter;
            if(letter.ToString() != "." && letter.ToString() != "," && letter.ToString() != ";" && letter.ToString() != ":" && letter.ToString() != "!" && letter.ToString() != "?" && letter.ToString() != " ") FindObjectOfType<AudioManager>().Play("VoiceSound");
            yield return new WaitForSeconds(textSpeed);
        }
    }

    void EndDialogue()
    {
        animator.SetBool("IsOpen", false);
    }
}
